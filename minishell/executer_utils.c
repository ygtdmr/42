/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:14:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/19 16:10:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "expand.h"

char	*path_resolve(char *file)
{
	char	**paths;
	char	*abs_path;
	int		i;

	if (access(file, X_OK) == 0)
		return (ft_strdup(file));
	i = 0;
	abs_path = 0;
	paths = ft_split(getenv("PATH"), ':');
	while (paths && paths[i])
	{
		abs_path = str_lrealloc(ft_strdup(paths[i]), "/", 1);
		abs_path = str_lrealloc(abs_path, file, ft_strlen(file));
		if (access(abs_path, X_OK) == 0)
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

int	str_match(char *dest, char *src)
{
	char	*s;
	if (!(dest && src))
		return (0);
	s = ft_strnstr(dest, src, ft_strlen(dest));
	return (s && (ft_strlen(dest) == ft_strlen(src)));
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

int	path_exists(t_shell *sh, char *file)
{
	char	*path;

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
	}
	sh->last_status = 127;
	return (0);
}
