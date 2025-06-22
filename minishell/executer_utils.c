/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:14:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/22 15:47:26 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "expand.h"
#include "str_utils.h"
#include <sys/stat.h>

void	exec_error(char	*msg, char *var)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	if (var)
		ft_putstr_fd(var, 2);
	ft_putchar_fd('\n', 2);
}

int	is_built_in(char *file)
{
	if (!file)
		return (0);
	return (
		str_match(file, "echo") || \
		str_match(file, "cd") || \
		str_match(file, "pwd") || \
		str_match(file, "export") || \
		str_match(file, "unset") || \
		str_match(file, "env") || \
		str_match(file, "exit")
	);
}

char	*path_resolve(char *file)
{
	char	**paths;
	char	*abs_path;
	int		i;

	if (access(file, F_OK) != -1)
		return (ft_strdup(file));
	i = 0;
	abs_path = 0;
	paths = ft_split(getenv("PATH"), ':');
	while (paths && paths[i])
	{
		abs_path = str_lrealloc(ft_strdup(paths[i]), "/", 1, 0);
		abs_path = str_lrealloc(abs_path, file, ft_strlen(file), 0);
		if (access(abs_path, F_OK) != -1)
		{
			while (paths && paths[i])
				free(paths[i++]);
			free(paths);
			return (abs_path);
		}
		free(abs_path);
		free(paths[i++]);
	}
	free(paths);
	return (0);
}

static int	path_exists(t_shell *sh, char *file)
{
	char	*path;
	struct stat st;

	if ((lstat(file, &st) != -1) && S_ISDIR(st.st_mode))
		return (0);
	if (is_built_in(file))
		return (1);
	if (getenv("PATH"))
	{
		path = path_resolve(file);
		if (path)
		{
			free(path);
			return (1);
		}
		free(path);
	}
	sh->last_status = 127 << 8;
	return (0);
}

static int	path_executable(t_shell *sh, char *file)
{
	char	*path;

	if (is_built_in(file))
		return (1);
	if (getenv("PATH"))
	{
		path = path_resolve(file);
		if (access(path, X_OK) == 0)
		{
			free(path);
			return (1);
		}
		free(path);
	}
	sh->last_status = 126 << 8;
	return (0);
}

int	path_validate(t_shell *sh, char *file)
{
	if (!path_exists(sh, file))
	{
		exec_error("command not found: ", file);
		return (0);
	}
	if (!path_executable(sh, file))
	{
		exec_error("permission denied: ", file);
		return (0);
	}
	return (1);
}
