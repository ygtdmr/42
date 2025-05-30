/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:30:16 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/29 23:52:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

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
		while(cmd->argv[j])
			printf("\"%s\", ", cmd->argv[j]);
		printf("]\n\tredir\t= {");
		redir = cmd->redir_head;
		while(redir)
		{
			printf("[type=%d, file=%s], ", redir->type, redir->file);
			redir = redir->next;
		}
		printf("}\n");
		cmd = cmd->next;
		i++;
	}
}

void	print_envp(t_shell *sh)
{
	t_env	*env;

	env = sh->env_head;
	while (env)
	{
		printf("%s=%s\n", env->key, env->value);
		env = env->next;
	}
}
