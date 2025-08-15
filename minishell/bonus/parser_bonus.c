/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:59:41 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/11 10:23:57 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	syntax_err(t_shell *sh, char *near)
{
	ft_putstr_fd("minishell: syntax error near unexpected token `", 2);
	if (near)
		ft_putstr_fd(near, 2);
	else
		ft_putstr_fd("newline", 2);
	ft_putstr_fd("'\n", 2);
	sh->last_status = 2 << 8;
	return (0);
}

static int	is_redir(int type)
{
	return (type == T_REDIR_IN || \
type == T_REDIR_OUT || \
type == T_REDIR_ERR || \
type == T_REDIR_APND || \
type == T_HEREDOC);
}

static int	check_err(t_shell *sh, t_token *token)
{
	if (token->type == T_WORD)
		return (1);
	if ((token->type == T_PIPE || is_operator(token->type)) && !token->prev)
		return (syntax_err(sh, token->value));
	if (token->type == T_SUB_OPEN && \
token->next && token->next->type == T_SUB_CLOSE)
		return (syntax_err(sh, token->next->value));
	if (token->type == T_SUB_OPEN || token->type == T_SUB_CLOSE)
		return (check_err_subsh(sh));
	if (!token->next)
		return (syntax_err(sh, 0));
	if (token->next->type != T_WORD && !is_redir(token->next->type) && \
token->next->type != T_SUB_OPEN)
		return (syntax_err(sh, token->next->value));
	if (is_redir(token->type))
	{
		if (!token->next)
			return (syntax_err(sh, 0));
		if (token->next->type != T_WORD)
			return (syntax_err(sh, token->next->value));
	}
	return (1);
}

static void	exit_parser(t_shell *sh, t_cmd **head)
{
	clear_cmd(head, 2);
	free(sh->prompt);
	sh->prompt = 0;
}

void	parser(t_shell *sh, t_token *token, t_cmd **head)
{
	t_cmd	*cmd;

	cmd = new_cmd(head, token);
	while (token)
	{
		if (!check_err(sh, token))
			return (exit_parser(sh, head));
		if (token->type == T_SUB_OPEN)
		{
			cmd->tok_subsh = grab_tok_subsh(&token);
			parser(sh, cmd->tok_subsh, &cmd->cmd_subsh);
			continue ;
		}
		else if (token->type == T_WORD)
			argv_push_with_willcard(&cmd->argv, token);
		else if (is_redir(token->type))
			redir_push(&cmd->redir_head, &token);
		else if (is_operator(token->type))
			cmd = new_cmd_op(head, token);
		else if (token && (token->type == T_PIPE))
			cmd = new_cmd(head, token);
		if (token)
			token = token->next;
	}
}
