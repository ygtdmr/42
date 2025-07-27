/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 07:01:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/27 11:18:49 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	heredoc(char *eof, int *pipefd)
{
	char	*line;

	signal(SIGINT, SIG_DFL);
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			ft_putendl_fd("minishell: warning: \
here-document delimited by end-of-file", 1);
			break ;
		}
		if (str_match(line, eof))
			break ;
		ft_putendl_fd(line, pipefd[1]);
		free(line);
	}
	if (line)
		free(line);
	close(pipefd[0]);
	close(pipefd[1]);
	exit(0);
}

static int	get_heredoc_fd(t_cmd *cmd, char *eof)
{
	int	pid;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		return (-3);
	pid = fork();
	if (pid == 0)
		heredoc(eof, pipefd);
	else if (pid > 0)
	{
		g_running = 1;
		waitpid(pid, &cmd->last_status, 0);
		g_running = 0;
		close(pipefd[1]);
		if (cmd->last_status > 0)
			return (-2);
		return (pipefd[0]);
	}
	return (-1);
}

static int	get_redir_fd(t_cmd *cmd, t_toktype type, char *file)
{
	int	fd;

	fd = -1;
	if (type == T_REDIR_OUT)
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == T_REDIR_APND)
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (type == T_REDIR_IN)
		fd = open(file, O_RDONLY);
	else if (type == T_HEREDOC)
		fd = get_heredoc_fd(cmd, file);
	return (fd);
}

int	is_redir(int type)
{
	return (type == T_REDIR_IN || \
type == T_REDIR_OUT || \
type == T_REDIR_APND || \
type == T_HEREDOC);
}

void	redir_push(t_cmd *cmd, t_redir **head, t_token **token)
{
	t_redir	*redir;
	t_redir	*new;

	if (cmd->redir_err)
		return ;
	new = malloc(sizeof(t_redir));
	if (!new)
		return ;
	new->type = (*token)->type;
	new->file = (*token)->next->value;
	new->fd = get_redir_fd(cmd, new->type, new->file);
	if (new->fd < 0)
		cmd->redir_err = 1;
	*token = (*token)->next;
	new->next = 0;
	if (!*head)
		*head = new;
	else
	{
		redir = *head;
		while (redir->next)
			redir = redir->next;
		redir->next = new;
	}
}
