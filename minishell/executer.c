/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:16:44 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/29 08:47:46 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "str_utils.h"

static int	apply_redirs(t_shell *sh, t_redir *redir)
{
	while (redir)
	{
		if (redir->fd < 0)
		{
			if (redir->type == T_REDIR_OUT || redir->type == T_REDIR_APND)
				dup2(redir->fd, 1);
			else if (redir->type == T_REDIR_IN || redir->type == T_HEREDOC)
				dup2(redir->fd, 0);
			if (redir->fd != -2)
			{
				perror("minishell");
				sh->last_status = 1 << 8;
			}
			return (0);
		}
		else
			close(redir->fd);
		redir = redir->next;
	}
	return (1);
}

static void	exec_in(t_shell *sh, t_cmd *cmd, int *pipefd)
{
	if (pipefd)
		dup2(pipefd[1], 1);
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

static void	exec_ext(t_shell *sh, t_cmd *cmd, int *pipefd, int readfd)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{	
		if (!cmd->redir_head && readfd != -1)
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

	bfd_std[0] = dup(0);
	bfd_std[1] = dup(1);
	if (apply_redirs(sh, cmd->redir_head))
	{
		sh->last_status = 0 << 8;
		if (cmd->argv)
		{
			g_interactive = 1;
			if (is_built_in(cmd->argv[0]))
				exec_in(sh, cmd, pipefd);
			else
				exec_ext(sh, cmd, pipefd, readfd);
			g_interactive = 0;
		}
	}
	dup2(bfd_std[0], 0);
	dup2(bfd_std[1], 1);
	close(bfd_std[0]);
	close(bfd_std[1]);
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
