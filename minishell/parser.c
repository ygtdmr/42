/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:59:41 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/29 23:57:18 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static	int	is_redir(int type)
{
	return (
		type == T_REDIR_IN \
		|| type == T_REDIR_OUT \
		|| type == T_REDIR_APND \
		|| type == T_HEREDOC
	);
}

void	parser(t_shell *sh)
{
	t_token	*token;
	t_cmd	*cmd;

	token = sh->token_head;
	cmd = new_cmd(&sh->cmd_head);
	if (token->type == T_PIPE || is_redir(token->type))
		return (syntax_err(token->value));
	while (token)
	{
		if (token->type == T_WORD)
			argv_push(&cmd->argv, token->value);
		else if(is_redir(token->type))
		{
			if (!token->next || token->next->type != T_WORD)
				return (syntax_err(token->value), clear_cmd(&sh->cmd_head));
			redir_push(&cmd->redir_head, *token);
		}
		else if (token->type == T_PIPE)
        {
            if (!token->next || token->next->type == T_PIPE)
				return (syntax_err(token->value), clear_cmd(&sh->cmd_head));
			cmd = new_cmd(&sh->cmd_head);
        }
		token = token->next;
	}
}
