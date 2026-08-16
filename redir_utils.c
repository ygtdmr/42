/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 07:01:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/10 12:14:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_redir_fd(t_redir *redir)
{
	int	fd;

	fd = -1;
	if (redir->type == T_REDIR_OUT || redir->type == T_REDIR_ERR)
		fd = open(redir->file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	else if (redir->type == T_REDIR_APND)
		fd = open(redir->file, O_CREAT | O_WRONLY | O_APPEND, 0644);
	else if (redir->type == T_REDIR_IN)
		fd = open(redir->file, O_RDONLY);
	return (fd);
}

static void	redir_fetch_heredoc_fds(t_shell *sh)
{
	t_cmd	*cmd;
	t_redir	*redir;

	cmd = sh->cmd_head;
	while (cmd)
	{
		redir = cmd->redir_head;
		while (redir)
		{
			if (redir->type == T_HEREDOC)
				redir->fd = get_heredoc_fd(sh, cmd, redir->file, redir->quote);
			redir = redir->next;
		}
		cmd = cmd->next;
	}
}

void	redir_fetch_fds(t_shell *sh)
{
	t_cmd	*cmd;
	t_redir	*redir;

	redir_fetch_heredoc_fds(sh);
	cmd = sh->cmd_head;
	while (cmd)
	{
		redir = cmd->redir_head;
		while (redir)
		{
			if (redir->type != T_HEREDOC)
				redir->fd = get_redir_fd(redir);
			if (redir->fd < 0 && redir->fd > -4)
				break ;
			redir = redir->next;
		}
		cmd = cmd->next;
	}
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
	new->quote = (*token)->quote;
	new->fd = -4;
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

void	change_fd(int *fd, int new)
{
	if (*fd != -1)
		close(*fd);
	*fd = new;
}
