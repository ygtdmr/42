/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:14:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/02 18:19:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "str_utils.h"
#include "env_utils.h"

int	is_built_in(char *file)
{
	if (!file)
		return (0);
	return (str_match(file, "echo") || \
str_match(file, "cd") || \
str_match(file, "pwd") || \
str_match(file, "export") || \
str_match(file, "unset") || \
str_match(file, "env") || \
str_match(file, "exit"));
}

char	*path_resolve(char **env, char *file)
{
	char	**paths;
	char	*abs_path;
	int		i;

	i = 0;
	abs_path = 0;
	paths = ft_split(env_get(env, "PATH"), ':');
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
	return (ft_strdup(""));
}

int	apply_redirs(t_cmd *cmd, int *infd, int *outfd)
{
	t_redir	*redir;

	redir = cmd->redir_head;
	while (redir)
	{
		if (redir->fd < 0)
		{
			cmd->last_status = 1 << 8;
			if (redir->fd == -1)
				perror("minishell");
			else if (redir->fd == -3)
				perror("minishell: pipe");
			return (0);
		}
		if (redir->type == T_REDIR_OUT || redir->type == T_REDIR_APND)
			*outfd = redir->fd;
		else if (redir->type == T_REDIR_IN || redir->type == T_HEREDOC)
			*infd = redir->fd;
		redir = redir->next;
	}
	return (1);
}

void	do_exec(char *path, char **argv, char **env)
{
	if (access(path, F_OK) != -1)
		path = ft_strdup(path);
	else if (env_get(env, "PATH"))
		path = path_resolve(env, path);
	else
		path = ft_strdup("");
	execve(path, argv, env);
	free(path);
	if (errno == ENOENT)
	{
		ft_putstr_fd(argv[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
	else
	{
		perror("minishell");
		if (errno == EACCES)
			exit(126);
		else
			exit(1);
	}
}
