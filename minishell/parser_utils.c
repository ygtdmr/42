/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 14:08:51 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/30 15:35:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	argv_push(char ***dest, char *src)
{
	char	**argv;
	int		i;

	i = 0;
	while (*dest && (*dest)[i])
		i++;
	argv = ft_calloc(i + 2, sizeof(char *));
	i = 0;
	while (*dest && (*dest)[i])
	{
		argv[i] = (*dest)[i];
		i++;
	}
	argv[i] = src;
	if (*dest)
		free(*dest);
	*dest = argv;
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

static void	clear_redir(t_redir *redir)
{
	if (!redir)
		return ;
	clear_redir(redir->next);
	free(redir);
}

void	clear_cmd(t_cmd **head)
{
	int		i;
	t_cmd	*cmd;

	i = 0;
	if (!head)
		return ;
	cmd = *head;
	if (!cmd)
		return ;
	free(cmd->argv);
	clear_redir(cmd->redir_head);
	if (cmd->next)
		clear_cmd(&cmd->next);
	free(cmd);
	*head = 0;
}

t_cmd	*new_cmd(t_cmd **head)
{
	t_cmd	*last_head;
	t_cmd	*new;

	if (!head)
		return (0);
	last_head = 0;
	new = malloc(sizeof(t_cmd));
	if (!new)
		return (0);
	ft_bzero(new, sizeof(t_cmd));
	if (*head)
	{
		last_head = *head;
		while (last_head->next)
			last_head = last_head->next;
		last_head->next = new;
	}
	else
		*head = new;
	return (new);
}
