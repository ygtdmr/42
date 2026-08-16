/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:59:41 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/10 12:14:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	syntax_err(t_shell *sh, char *near)
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
	if (!token->next)
		return (syntax_err(sh, 0));
	if (token->next->type != T_WORD && !is_redir(token->next->type))
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

static void	exit_parser(t_shell *sh)
{
	clear_cmd(&sh->cmd_head);
	free(sh->prompt);
	sh->prompt = 0;
}

void	parser(t_shell *sh)
{
	t_token	*token;
	t_cmd	*cmd;

	token = sh->token_head;
	if (!token)
		return ;
	if (token->type == T_PIPE)
		return ((void)syntax_err(sh, token->value));
	cmd = new_cmd(&sh->cmd_head);
	while (token)
	{
		if (!check_err(sh, token))
			return (exit_parser(sh));
		if (token->type == T_WORD)
			argv_push(&cmd->argv, token->value);
		else if (is_redir(token->type))
			redir_push(&cmd->redir_head, &token);
		else if (token->type == T_PIPE)
			cmd = new_cmd(&sh->cmd_head);
		token = token->next;
	}
}
