/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subshell_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:29:00 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/16 08:37:03 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_bonus.h"
#include "env_utils_bonus.h"
#include "parser_bonus.h"
#include "executer_bonus.h"

int	cmd_has_pipe(t_shell *sh, t_cmd *cmd)
{
	int	par;

	if (sh->par == cmd->par)
		return (cmd->next && !(cmd->and_op + cmd->or_op) && \
	sh->par == cmd->next->par);
	else
	{
		par = cmd->par;
		while (cmd)
		{
			if (cmd->par != par)
				return (cmd->next && !(cmd->and_op + cmd->or_op));
			cmd = cmd->next;
		}
		return (0);
	}
}

static void	run(t_shell *sh, int readfd, int outfd)
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
		executer(sh);
		clear_env(sh->env);
		exit(compile_status(sh->last_status));
	}
	else if (pid > 0)
		sh->cmd_head->pid = pid;
	else
		perror("minishell: fork");
}

void	subshell(t_shell *sh, t_cmd **cmd, int readfd, int outfd)
{
	t_shell	sub_sh;

	ft_bzero(&sub_sh, sizeof(sh));
	sub_sh.env = env_dup(sh->env, 0);
	sub_sh.cmd_head = *cmd;
	sub_sh.par = (*cmd)->par;
	run(&sub_sh, readfd, outfd);
}
