/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 06:50:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/11 07:22:22 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_bonus.h"

int	is_operator(t_toktype type)
{
	return (type == T_OPERATOR_OR || type == T_OPERATOR_AND);
}

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

void	skip_cmd(t_cmd **cmd, int operator)
{
	while (*cmd)
	{
		if (((*cmd)->and_op && operator) || ((*cmd)->or_op && !operator))
			break ;
		else
			*cmd = (*cmd)->next;
	}
	if ((*cmd))
		*cmd = (*cmd)->next;
}

void	clear_cmd(t_cmd **head)
{
	t_cmd	*cmd;
	t_redir	*redir;

	if (!head)
		return ;
	cmd = *head;
	if (!cmd)
		return ;
	free(cmd->argv);
	while (cmd->redir_head)
	{
		redir = cmd->redir_head->next;
		free(cmd->redir_head);
		cmd->redir_head = redir;
	}
	if (cmd->next)
		clear_cmd(&cmd->next);
	free(cmd);
	*head = 0;
}
