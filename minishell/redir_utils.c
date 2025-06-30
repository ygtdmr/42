/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 07:01:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/29 08:47:29 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redir_utils.h"
#include "str_utils.h"

static int	do_heredoc(char *eof, int *pipefd)
{
	char	*line;

	if (!eof)
	{
		ft_putendl_fd("minishell: syntax error: newline unexpected", 2);
		return (-1);
	}
	g_interactive = 1;
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			dup2(open("/dev/tty", O_RDONLY), 0);
			g_interactive = 0;
			return (-2);
		}
		if (str_mc(&line, eof))
			break ;
		ft_putendl_fd(line, pipefd[1]);
		free(line);
	}
	g_interactive = 0;
	return (pipefd[0]);
}

static int	do_redir(t_redir *redir)
{
	int	fd;
	int	pipefd[2];

	if (pipe(pipefd) == -1)
	{
		perror("minishell: pipe");
		return (-1);
	}
	if (redir->type == T_REDIR_OUT)
		fd = open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (redir->type == T_REDIR_APND)
		fd = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (redir->type == T_REDIR_IN)
		fd = open(redir->file, O_RDONLY);
	if ((redir->type == T_REDIR_OUT || redir->type == T_REDIR_APND) && fd != -1)
		dup2(fd, pipefd[1]);
	else if (redir->type == T_REDIR_IN && fd != -1)
		dup2(fd, pipefd[0]);
	if (redir->type == T_HEREDOC)
		fd = do_heredoc(redir->file, pipefd);
	close(pipefd[1]);
	close(pipefd[0]);
	return (fd);
}

int	is_redir(int type)
{
	return (type == T_REDIR_IN || \
type == T_REDIR_OUT || \
type == T_REDIR_APND || \
type == T_HEREDOC);
}

void	redir_push(t_redir **head, t_token **token)
{
	t_redir	*redir;
	t_redir	*new;

	new = malloc(sizeof(t_redir));
	if (!new)
		return ;
	new->type = (*token)->type;
	new->file = (*token)->next->value;
	new->fd = do_redir(new);
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
