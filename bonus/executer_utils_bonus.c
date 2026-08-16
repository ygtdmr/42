/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:14:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/07 05:48:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*path_resolve(char **env, char *file)
{
	char	**paths;
	char	*abs_path;
	int		i;

	if (str_match(file, ".") || str_match(file, ".."))
		return (0);
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
	return (0);
}

static void	apply_redir_err(t_redir *redir)
{
	if (redir->type != T_REDIR_ERR)
		return ;
	dup2(redir->fd, 2);
	close(redir->fd);
}

int	apply_redirs(t_cmd *cmd, int *infd, int *outfd)
{
	t_redir	*redir;

	redir = cmd->redir_head;
	while (redir)
	{
		if (redir->fd < 0 && redir->fd > -4)
		{
			cmd->last_status = (redir->fd == -1 || redir->fd == -3) << 8;
			if (redir->fd == -1)
			{
				ft_putstr_fd("minishell: ", 2);
				perror(redir->file);
			}
			else if (redir->fd == -3)
				perror("minishell: pipe");
			return (0);
		}
		apply_redir_err(redir);
		if (redir->type == T_REDIR_OUT || redir->type == T_REDIR_APND)
			change_fd(outfd, redir->fd);
		else if (redir->type == T_REDIR_IN || redir->type == T_HEREDOC)
			change_fd(infd, redir->fd);
		redir = redir->next;
	}
	return (1);
}

void	valid_path(char *path, char **env)
{
	struct stat	st;

	if (ft_strchr(path, '/') || !env_get(env, "PATH"))
	{
		if (stat(path, &st) != -1)
		{
			if (S_ISDIR(st.st_mode))
			{
				ft_putendl_fd("minishell: Is a directory", 2);
				exit(126);
			}
			if (access(path, X_OK) == -1)
			{
				ft_putendl_fd("minishell: Permission denied", 2);
				exit(126);
			}
		}
		else
		{
			ft_putstr_fd("minishell: No such file or directory", 2);
			exit(127);
		}
	}
}

void	do_exec(char *path, char **argv, char **env, int noenv)
{
	valid_path(path, env);
	if (ft_strchr(path, '/') && access(path, X_OK) != -1)
		path = ft_strdup(path);
	else if (*path && env_get(env, "PATH"))
		path = path_resolve(env, path);
	if (!path || !*path)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putendl_fd(": command not found", 2);
		if (path)
			free(path);
		exit(127);
	}
	if (noenv)
		execve(path, argv, 0);
	else
		execve(path, argv, env);
	free(path);
	perror("minishell");
	exit(1);
}
