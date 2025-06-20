/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:16:44 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/20 14:32:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	exec_error(char	*msg, char *var)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(msg, 2);
	if (var)
		ft_putstr_fd(var, 2);
	ft_putchar_fd('\n', 2);
}

static void	built_in_or_exec(t_shell *sh, char *path, char **argv)
{
	if (!is_built_in(path))
		execve(path_resolve(argv[0]), argv, sh->env);
	else if (str_match(path, "echo"))
		bi_echo(argv);
	else if (str_match(path, "pwd"))
		bi_pwd(argv);
	else if (str_match(path, "env"))
		bi_env(sh->env);
	else
		exit(0);
}

static void	built_in_before_exec(t_shell *sh, t_cmd **cmd)
{
	int		is_run;
	char	**argv;

	if ((*cmd)->next)
		return ;
	is_run = 1;
	argv = (*cmd)->argv;
	if (str_match(argv[0], "cd"))
		bi_cd(argv);
	if (str_match(argv[0], "exit"))
		bi_exit(sh);
	else
		is_run = 0;
	if (is_run)
		(*cmd) = 0;
}

static void	execute(t_shell *sh, char **argv, int *pipefd, int readfd)
{
	pid_t	pid;

	if (!path_exists(sh, argv[0]))
		return (exec_error("command not found: ", argv[0]));
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
		built_in_or_exec(sh, argv[0], argv);
	}
	else if (pid > 0)
		waitpid(pid, &sh->last_status, 0);
	else
		exec_error("fork error", 0);
}

void	executer(t_shell *sh)
{
	int		pipefd[2];
	int		readfd;
	t_cmd	*cmd;

	readfd = -1;
	cmd = sh->cmd_head;
	built_in_before_exec(sh, &cmd);
	while (cmd)
	{
		if (cmd->next)
		{
			if (pipe(pipefd) == -1)
				exec_error("pipe error", 0);
			execute(sh, cmd->argv, pipefd, readfd);
			close(pipefd[1]);
			if (readfd != -1)
				close(readfd);
			readfd = pipefd[0];
		}
		else
			execute(sh, cmd->argv, 0, readfd);
		cmd = cmd->next;
	}
	if (readfd != -1)
		close(readfd);
}
