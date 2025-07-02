/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:16:44 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/02 19:48:53 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "parser.h"
#include "built_in.h"
#include "str_utils.h"

static void	exec_in(t_shell *sh, t_cmd *cmd, int readfd, int outfd)
{
	char bf[1];
	// t_cmd	*cmd_before;

	if (!apply_redirs(cmd, &readfd, &outfd))
		return ;
	// cmd_before = get_cmd_before(sh->cmd_head, cmd);
	// if (readfd != -1)
	// {
	// 	if (cmd_before->pid > 0)
	// 		kill(cmd_before->pid, SIGKILL);
	// }
	if (readfd != -1)
	{
		while (read(readfd, bf, sizeof(bf)) > 0)
			close(readfd);
	}
	if (outfd == -1)
		outfd = 1;
	if (str_match(cmd->argv[0], "echo"))
		bi_echo(outfd, cmd->argv);
	else if (str_match(cmd->argv[0], "pwd"))
		bi_pwd(outfd, cmd->argv);
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

static int	exec_ext(t_shell *sh, t_cmd *cmd, int readfd, int outfd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (!apply_redirs(cmd, &readfd, &outfd))
			exit(1);
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
	return (pid);
}

static void	launch(t_shell *sh, t_cmd *cmd, int readfd, int outfd)
{
	cmd->last_status = 0;
	if (cmd->argv)
	{
		if (is_built_in(cmd->argv[0]))
			exec_in(sh, cmd, readfd, outfd);
		else
			exec_ext(sh, cmd, readfd, outfd);
	}
}

static void	wait_process(t_shell *sh)
{
	t_cmd	*cmd;

	cmd = sh->cmd_head;
	g_interactive = 1;
	while (cmd)
	{
		if (cmd->pid > 0)
			waitpid(cmd->pid, &cmd->last_status, 0);
		if (!cmd->next)
			sh->last_status = cmd->last_status;
		cmd = cmd->next;
	}
	if (!isatty(0))
		open("/dev/tty", O_RDONLY);
	g_interactive = 0;
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
			launch(sh, cmd, readfd, pipefd[1]);
			close(pipefd[1]);
			if (readfd != -1)
				close(readfd);
			readfd = pipefd[0];
		}
		else
			launch(sh, cmd, readfd, -1);
		cmd = cmd->next;
	}
	if (readfd != -1)
		close(readfd);
	wait_process(sh);
}
