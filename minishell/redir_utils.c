/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 07:01:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/28 06:29:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_redir_fd(t_shell *sh, t_cmd *cmd, t_toktype type, char *file)
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
		fd = get_heredoc_fd(sh, cmd, file);
	return (fd);
}

int	is_redir(int type)
{
	return (type == T_REDIR_IN || \
type == T_REDIR_OUT || \
type == T_REDIR_APND || \
type == T_HEREDOC);
}

void	redir_push(t_shell *sh, t_cmd *cmd, t_redir **head, t_token **token)
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
	new->fd = get_redir_fd(sh, cmd, new->type, new->file);
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
