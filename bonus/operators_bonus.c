/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operators_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 07:34:34 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/14 13:56:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	is_operator(t_toktype type)
{
	return (type == T_OP_AND || type == T_OP_OR);
}

int	op_mc(t_shell *sh, char **line)
{
	if (str_mc(line, "&&"))
	{
		new_tok(&sh->token_head, ft_strdup("&&"), T_OP_AND);
		return (1);
	}
	if (str_mc(line, "||"))
	{
		new_tok(&sh->token_head, ft_strdup("||"), T_OP_OR);
		return (1);
	}
	return (0);
}

t_cmd	*new_cmd_op(t_cmd **head, t_token *token)
{
	t_cmd	*cmd;

	cmd = new_cmd(head, token);
	if (token->type == T_OP_AND)
		cmd->op = 1;
	else if (token->type == T_OP_OR)
		cmd->op = 0;
	return (cmd);
}

void	update_cmd_argv(t_shell *sh, t_cmd *head)
{
	t_token	*token;

	while (head)
	{
		token = head->token;
		if (head->argv)
		{
			clear_sl(head->argv);
			head->argv = 0;
			while (token)
			{
				if (token->type == T_WORD)
				{
					free(token->value);
					token->value = expand(sh, ft_strdup(token->raw_word));
					argv_push_with_willcard(&head->argv, token);
				}
				token = token->next;
				if (token && is_operator(token->type))
					break ;
			}
		}
		head = head->next;
	}
}
