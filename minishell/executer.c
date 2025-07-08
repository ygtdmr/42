/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:16:44 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/08 15:25:08 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "parser.h"
#include "built_in.h"
#include "str_utils.h"

static void	exec_in(t_shell *sh, t_cmd *cmd, int outfd)
{
	if (outfd == -1)
		outfd = 1;
	if (str_match(cmd->argv[0], "echo"))
		bi_echo(outfd, cmd->argv);
	else if (str_match(cmd->argv[0], "pwd"))
		bi_pwd(outfd);
	else if (str_match(cmd->argv[0], "env"))
		bi_env(outfd, sh->env);
	else if (str_match(cmd->argv[0], "cd"))
		bi_cd(outfd, sh, cmd);
	else if (str_match(cmd->argv[0], "export"))
		bi_export(sh, cmd, cmd->next != 0);
	else if (str_match(cmd->argv[0], "unset"))
		bi_unset(sh, cmd, cmd->next != 0);
	else if (str_match(cmd->argv[0], "exit"))
		bi_exit(sh, cmd, cmd->next != 0);
}

static void	exec_ext(t_shell *sh, t_cmd *cmd, int readfd, int outfd)
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
		do_exec(cmd->argv[0], cmd->argv, sh->env);
	}
	else if (pid > 0)
		cmd->pid = pid;
	else
		perror("minishell: fork");
}

static void	launch(t_shell *sh, t_cmd *cmd, int readfd, int outfd)
{
	if (apply_redirs(cmd, &readfd, &outfd) && cmd->argv)
	{
		if (is_bi(cmd->argv[0]))
			exec_in(sh, cmd, outfd);
		else
			exec_ext(sh, cmd, readfd, outfd);
	}
	if (readfd != -1)
		close(readfd);
	if (outfd != -1)
		close(outfd);
}

static void	wait_process(t_shell *sh)
{
	t_cmd	*cmd;

	cmd = sh->cmd_head;
	g_running = 1;
	while (cmd)
	{
		if (cmd->pid > 0)
			waitpid(cmd->pid, &cmd->last_status, 0);
		if (!cmd->next)
			sh->last_status = cmd->last_status;
		cmd = cmd->next;
	}
	g_running = 0;
	if (!isatty(0))
		open("/dev/tty", O_RDONLY);
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
				return (perror("minishell: pipe"));
			if (cmd->argv && !is_bi(cmd->argv[0]) && is_bi(cmd->next->argv[0]))
				close(pipefd[0]);
			launch(sh, cmd, readfd, pipefd[1]);
			readfd = pipefd[0];
		}
		else
			launch(sh, cmd, readfd, -1);
		cmd = cmd->next;
	}
	wait_process(sh);
}
