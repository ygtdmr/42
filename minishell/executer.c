/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:16:44 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/27 19:25:02 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "str_utils.h"

static int	apply_redirs(t_redir *redir)
{
	int	fd;

	while (redir)
	{
		fd = do_redir(redir);
		if (fd == -1)
		{
			perror("minishell");
			return (0);
		}
		else
			close(fd);
		redir = redir->next;
	}
	return (1);
}

static void	exec_in(t_shell *sh, t_cmd *cmd, int *pipefd)
{
	if (pipefd)
		dup2(pipefd[1], 1);
	if (apply_redirs(cmd->redir_head))
	{
		if (str_match(cmd->argv[0], "echo"))
			bi_echo(cmd->argv);
		else if (str_match(cmd->argv[0], "pwd"))
			bi_pwd(cmd->argv);
		else if (str_match(cmd->argv[0], "env"))
			bi_env(sh->env);
		else if (str_match(cmd->argv[0], "cd"))
			bi_cd(sh, cmd->argv);
		else if (str_match(cmd->argv[0], "export"))
			bi_export(sh, cmd->argv);
		else if (str_match(cmd->argv[0], "unset"))
			bi_unset(sh, cmd->argv);
	}
	else
		sh->last_status = 1 << 8;
}

static void	exec_ext(t_shell *sh, t_cmd *cmd, int *pipefd, int readfd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if (!apply_redirs(cmd->redir_head))
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
		waitpid(pid, &sh->last_status, 0);
	else
		perror("minishell: fork");
}

static void	launch(t_shell *sh, t_cmd *cmd, int *pipefd, int readfd)
{
	int	bfd_std[2];
	if (!cmd->argv)
		return ;
	sh->last_status = 0 << 8;
	if (is_built_in(cmd->argv[0]))
	{
		if (pipefd || cmd->redir_head)
		{
			bfd_std[0] = dup(0);
			bfd_std[1] = dup(1);
		}
		exec_in(sh, cmd, pipefd);
		if (pipefd || cmd->redir_head)
		{
			dup2(bfd_std[0], 0);
			dup2(bfd_std[1], 1);
			close(bfd_std[0]);
			close(bfd_std[1]);
		}
	}
	else
		exec_ext(sh, cmd, pipefd, readfd);
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
}
