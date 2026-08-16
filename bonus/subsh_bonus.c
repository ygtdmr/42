/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subsh_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 14:22:05 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/10 10:54:11 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	check_err_subsh(t_shell *sh)
{
	t_token	*token;
	int		sub;
	char	*near;

	token = sh->token_head;
	sub = 0;
	near = 0;
	while (token)
	{
		sub += (token->type == T_SUB_OPEN) || (token->type == T_SUB_CLOSE);
		if (!token->next && (sub % 2))
			return (syntax_err(sh, near));
		if (token->type == T_WORD && \
(token->next && token->next->type == T_SUB_OPEN))
			return (syntax_err(sh, token->value));
		if ((token->type == T_WORD || token->type == T_SUB_OPEN) && \
(token->prev && token->prev->type == T_SUB_CLOSE))
			return (syntax_err(sh, token->value));
		if (sub % 2)
			near = 0;
		else
			near = token->value;
		token = token->next;
	}
	return (1);
}

t_token	*grab_tok_subsh(t_token **head)
{
	t_token	*tok;
	int		len_sub;
	int		sub;

	len_sub = 0;
	tok = *head;
	while (tok)
	{
		len_sub += (tok->type == T_SUB_OPEN);
		len_sub -= (tok->type == T_SUB_CLOSE);
		tok = tok->next;
	}
	sub = 1;
	(*head) = (*head)->next;
	while ((*head) && sub != len_sub)
	{
		sub += ((*head)->type == T_SUB_OPEN);
		sub -= ((*head)->type == T_SUB_CLOSE);
		if (sub != len_sub)
			new_tok(&tok, ft_strdup((*head)->value), (*head)->type);
		(*head) = (*head)->next;
	}
	return (tok);
}

void	exec_sub(t_shell *sh, t_cmd *cmd, int readfd, int outfd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (readfd != -1)
		{
			dup2(readfd, 0);
			close(readfd);
		}
		if (outfd != -1)
		{
			dup2(outfd, 1);
			close(outfd);
		}
		sh->cmd_head = cmd->cmd_subsh;
		executer(sh);
		exit(compile_status(sh->last_status));
	}
	else if (pid > 0)
		cmd->pid = pid;
	else
		perror("minishell: fork");
}
