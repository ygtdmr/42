/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:16:44 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/23 19:33:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "str_utils.h"

static void	exec_in(t_shell *sh, char **argv, int *pipefd)
{
	int	bfd;

	sh->last_status = 0 << 8;
	if (pipefd)
	{
		bfd = dup(1);
		dup2(pipefd[1], 1);
	}
	if (str_match(argv[0], "echo"))
		bi_echo(argv);
	else if (str_match(argv[0], "pwd"))
		bi_pwd(argv);
	else if (str_match(argv[0], "env"))
		bi_env(sh->env);
	else if (str_match(argv[0], "cd"))
		bi_cd(sh, argv);
	else if (str_match(argv[0], "export"))
		bi_export(sh, argv);
	else if (str_match(argv[0], "unset"))
		bi_unset(sh, argv);
	if (pipefd)
	{
		dup2(bfd, 1);
		close(bfd);
	}
}

static void	exec_ext(t_shell *sh, char **argv, int *pipefd, int readfd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (pipefd)
		{
			dup2(pipefd[0], 0);
			dup2(pipefd[1], 1);
			close(pipefd[0]);
			close(pipefd[1]);
		}
		if (readfd != -1)
		{
			dup2(readfd, 0);
			close(readfd);
		}
		do_exec(argv[0], argv, sh->env);
	}
	else if (pid > 0)
		waitpid(pid, &sh->last_status, 0);
	else
		perror("minishell: fork");
}

static void	exec_in_or_out(t_shell *sh, char **argv, int *pipefd, int readfd)
{
	if (is_built_in(argv[0]))
		exec_in(sh, argv, pipefd);
	else
		exec_ext(sh, argv, pipefd, readfd);
}

void	executer(t_shell *sh)
{
	int		pipefd[2];
	int		readfd;
	t_cmd	*cmd;

	readfd = -1;
	cmd = sh->cmd_head;
	while (cmd)
	{
		if (cmd->next)
		{
			if (pipe(pipefd) == -1)
				perror("minishell: pipe");
			exec_in_or_out(sh, cmd->argv, pipefd, readfd);
			close(pipefd[1]);
			if (readfd != -1)
				close(readfd);
			readfd = pipefd[0];
		}
		else
			exec_in_or_out(sh, cmd->argv, 0, readfd);
		cmd = cmd->next;
	}
	if (readfd != -1)
		close(readfd);
}
