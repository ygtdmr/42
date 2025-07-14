/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 07:01:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/14 18:15:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "redir_utils_bonus.h"
#include "str_utils_bonus.h"

static int	get_heredoc_fd(char *eof, int *pipefd)
{
	char	*line;

	g_running = 1;
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			if (!isatty(0))
			{
				open("/dev/tty", O_RDONLY);
				pipefd[0] = -2;
			}
			break ;
		}
		if (str_match(line, eof))
			break ;
		ft_putendl_fd(line, pipefd[1]);
		free(line);
	}
	if (line)
		free(line);
	g_running = 0;
	close(pipefd[1]);
	return (pipefd[0]);
}

int	get_redir_fd(t_toktype type, char *file)
{
	int	fd;
	int	pipefd[2];

	fd = -1;
	if (type == T_REDIR_OUT)
		fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (type == T_REDIR_APND)
		fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (type == T_REDIR_IN)
		fd = open(file, O_RDONLY);
	else if (type == T_HEREDOC)
	{
		if (!file)
		{
			ft_putendl_fd("minishell: syntax error: newline unexpected", 2);
			return (-2);
		}
		if (pipe(pipefd) == -1)
			return (-3);
		fd = get_heredoc_fd(file, pipefd);
	}
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
	new->fd = -4;
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
