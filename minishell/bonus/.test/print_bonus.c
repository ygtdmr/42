/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:30:16 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/09 15:23:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_bonus.h"

void	print_tokens(t_shell *sh)
{
	t_token	*token;

	token = sh->token_head;
	while (token)
	{
		printf("[%d:%s] ", token->type, token->value);
		token = token->next;
	}
	printf("\n");
}

void	print_cmd(t_shell *sh)
{
	int		i;
	int		j;
	t_cmd	*cmd;
	t_redir	*redir;

	cmd = sh->cmd_head;
	i = 0;
	while (cmd)
	{
		j = 0;
		printf("cmd[%d]:\n", i);
		printf("\targv\t= [");
		while (cmd->argv && cmd->argv[j])
			printf("\"%s\", ", cmd->argv[j++]);
		printf("]\n\tredir\t= {");
		redir = cmd->redir_head;
		while (redir)
		{
			printf("[type=%d, file=%s, fd=%d], ", redir->type, redir->file, redir->fd);
			redir = redir->next;
		}
		printf("}\n\tops\t= [AND=%d, OR=%d]\n", cmd->and_op, cmd->or_op);
		cmd = cmd->next;
		i++;
	}
}
