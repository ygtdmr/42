/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:59:41 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/08 14:04:11 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "redir_utils.h"

static int	syntax_err(char *near)
{
	ft_putstr_fd("minishell: syntax error near unexpected token '", 2);
	if (near)
		ft_putstr_fd(near, 2);
	else
		ft_putstr_fd("newline", 2);
	ft_putstr_fd("'\n", 2);
	return (0);
}

static	int	check_err(t_token *token)
{
	if (token->type == T_WORD)
		return (1);
	if (!token->next)
		return (syntax_err(0));
	else if ((token->next->type != T_WORD) && !is_redir(token->next->type))
		return (syntax_err(token->value));
	return (1);
}

void	parser(t_shell *sh)
{
	t_token	*token;
	t_cmd	*cmd;

	token = sh->token_head;
	if (!token)
		return ;
	if (token->type == T_PIPE)
		return ((void) syntax_err(token->value));
	cmd = new_cmd(&sh->cmd_head);
	while (token)
	{
		if (!check_err(token))
			return (clear_cmd(&sh->cmd_head));
		if (token->type == T_WORD)
			argv_push(&cmd->argv, token->value);
		else if (is_redir(token->type))
			redir_push(cmd, &cmd->redir_head, &token);
		else if (token->type == T_PIPE)
			cmd = new_cmd(&sh->cmd_head);
		token = token->next;
	}
}
