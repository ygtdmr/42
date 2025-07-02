/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:16:44 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/01 16:51:21 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "built_in.h"
#include "str_utils.h"

static void	exec_in(t_shell *sh, t_cmd *cmd, int *pipefd)
{
	int	fd[2];

	fd[0] = 0;
	fd[1] = 1;
	if (pipefd)
	{
		fd[0] = pipefd[0];
		fd[1] = pipefd[1];
	}
	if (!apply_redirs(sh, cmd->redir_head, &fd[0], &fd[1]))
		return ;
	if (str_match(cmd->argv[0], "echo"))
		bi_echo(fd[1], cmd->argv);
	else if (str_match(cmd->argv[0], "pwd"))
		bi_pwd(fd[1], cmd->argv);
	else if (str_match(cmd->argv[0], "env"))
		bi_env(fd[1], sh->env);
	else if (str_match(cmd->argv[0], "cd"))
		bi_cd(fd[1], sh, cmd->argv);
	else if (str_match(cmd->argv[0], "export"))
		bi_export(sh, cmd->argv, cmd->next != 0);
	else if (str_match(cmd->argv[0], "unset"))
		bi_unset(sh, cmd->argv, cmd->next != 0);
	else if (str_match(cmd->argv[0], "exit"))
		bi_exit(sh, cmd->argv, cmd->next != 0);
}

static void	wait_ext_exec(t_shell *sh)
{
	while (sh->exec_ext_length)
	{
		waitpid(-1, &sh->last_status, 0);
		sh->exec_ext_length--;
	}
}

static int	exec_ext(t_shell *sh, t_cmd *cmd, int *pipefd, int readfd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (!apply_redirs(sh, cmd->redir_head, &readfd, &pipefd[1]))
			exit(1);
		if (readfd != -1)
		{
			dup2(readfd, 0);
			close(readfd);
		}
		if (pipefd)
		{
			dup2(pipefd[1], 1);
			close(pipefd[0]);
			close(pipefd[1]);
		}
		do_exec(cmd->argv[0], cmd->argv, sh->env);
	}
	else if (pid > 0)
		sh->exec_ext_length++;
	else
		perror("minishell: fork");
	return (pid);
}

static void	launch(t_shell *sh, t_cmd *cmd, int *pipefd, int readfd)
{
	sh->last_status = 0 << 8;
	if (cmd->argv)
	{
		g_interactive = 1;
		if (is_built_in(cmd->argv[0]))
			exec_in(sh, cmd, pipefd);
		else
			exec_ext(sh, cmd, pipefd, readfd);
		if (!isatty(0))
			open("/dev/tty", O_RDONLY);
		g_interactive = 0;
	}
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
			launch(sh, cmd, pipefd, readfd);
			close(pipefd[1]);
			if (readfd != -1)
				close(readfd);
			readfd = pipefd[0];
		}
		else
			launch(sh, cmd, 0, readfd);
		cmd = cmd->next;
	}
	if (readfd != -1)
		close(readfd);
	wait_ext_exec(sh);
}
