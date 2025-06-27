/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:14:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/27 19:29:53 by yidemir          ###   ########.fr       */
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

	if (access(file, F_OK) != -1)
		return (ft_strdup(file));
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

int	do_heredoc(char *eof)
{
	char	*line;
	int		pipefd[2];

	line = 0;
	if (!eof)
	{
		ft_putendl_fd("minishell: syntax error: newline unexpected", 2);
		return (-1);
	}
	if (pipe(pipefd) == -1)
	{
		perror("minishell: pipe");
		return (-1);
	}
	while (1)
	{
		line = readline("> ");
		if (str_mc(&line, eof))
			break;
		ft_putendl_fd(line, pipefd[1]);
		free(line);
	}
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	return (pipefd[1]);
}

int	do_redir(t_redir *redir)
{
	int		fd;

	if (redir->type == T_REDIR_OUT)
		fd = open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (redir->type == T_REDIR_APND)
		fd = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (redir->type == T_REDIR_IN)
		fd = open(redir->file, O_RDONLY);
	if ((redir->type == T_REDIR_OUT || redir->type == T_REDIR_APND) && fd != -1)
			dup2(fd, 1);
	else if (redir->type == T_REDIR_IN && fd != -1)
		dup2(fd, 0);
	if (redir->type == T_HEREDOC)
	{
		g_in_heredoc = 1;
		signal(SIGINT, SIG_IGN);
		fd = do_heredoc(redir->file);
		g_in_heredoc = 0;
	}
	return (fd);
}

void	do_exec(char *path, char **argv, char **env)
{
	if (env_get(env, "PATH"))
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
