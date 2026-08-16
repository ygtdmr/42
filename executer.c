/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:16:44 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/14 14:58:00 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exec_in(t_shell *sh, t_cmd *cmd, int readfd, int outfd)
{
	int	fds[2];
	int	has_pipe;

	has_pipe = (readfd != -1) || (outfd != -1);
	fds[0] = readfd;
	if (outfd == -1)
		outfd = 1;
	fds[1] = outfd;
	if (str_match(cmd->argv[0], "echo"))
		bi_echo(outfd, cmd->argv);
	else if (str_match(cmd->argv[0], "pwd"))
		bi_pwd(outfd);
	else if (str_match(cmd->argv[0], "env"))
		bi_env(fds, cmd, env_dup(sh->env, 0));
	else if (str_match(cmd->argv[0], "cd"))
		bi_cd(outfd, sh, cmd, has_pipe);
	else if (str_match(cmd->argv[0], "export"))
		bi_export(outfd, sh, cmd, has_pipe);
	else if (str_match(cmd->argv[0], "unset"))
		bi_unset(sh, cmd, has_pipe);
	else if (str_match(cmd->argv[0], "exit"))
		bi_exit(sh, cmd, has_pipe);
	if (cmd->prev && cmd->prev->pid > 0)
		kill(cmd->prev->pid, SIGKILL);
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
		do_exec(cmd->argv[0], cmd->argv, sh->env, 0);
	}
	else if (pid > 0)
		cmd->pid = pid;
	else
		perror("minishell: fork");
}

static void	launch(t_shell *sh, t_cmd *cmd, int readfd, int outfd)
{
	int	errfd;

	errfd = dup(2);
	if (cmd->argv)
		env_append(&sh->env, "_", ft_strdup(cmd->argv[0]));
	if (apply_redirs(cmd, &readfd, &outfd) && cmd->argv)
	{
		if (is_bi(cmd->argv[0]))
			exec_in(sh, cmd, readfd, outfd);
		else
			exec_ext(sh, cmd, readfd, outfd);
	}
	if (readfd != -1)
		close(readfd);
	if (outfd != -1)
		close(outfd);
	dup2(errfd, 2);
	close(errfd);
}

static void	wait_process(t_shell *sh)
{
	pid_t	pid;
	t_cmd	*cmd;
	int		len;
	int		last_status;

	len = 0;
	cmd = sh->cmd_head;
	while (cmd && ++len)
		cmd = cmd->next;
	set_running(1);
	while (len)
	{
		pid = waitpid(-1, &last_status, WNOHANG);
		if (pid > 0)
		{
			cmd = cmd_by_pid(sh->cmd_head, pid);
			cmd->last_status = last_status;
			if (cmd->prev && cmd->prev->pid > 0)
				kill(cmd->prev->pid, SIGPIPE);
		}
		len -= (pid != 0);
		usleep(1000);
	}
	set_running(0);
	sh->last_status = last_cmd(sh->cmd_head)->last_status;
}

void	executer(t_shell *sh)
{
	int		pipefd[2];
	int		readfd;
	t_cmd	*cmd;

	readfd = -1;
	cmd = sh->cmd_head;
	redir_fetch_fds(sh);
	while (cmd)
	{
		if (cmd->next)
		{
			if (pipe(pipefd) == -1)
				return (perror("minishell: pipe"));
			launch(sh, cmd, readfd, pipefd[1]);
			readfd = pipefd[0];
		}
		else
			launch(sh, cmd, readfd, -1);
		cmd = cmd->next;
	}
	if (sh->cmd_head)
		wait_process(sh);
}
