/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:16:44 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/07 14:05:15 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"

static void	execute(t_shell *sh, t_cmd *cmd, int *pipefd, int fd)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (pipefd)
		{
			dup2(pipefd[fd], fd);
			close(pipefd[0]);
			close(pipefd[1]);
		}
        execve(path_resolve(cmd->argv[0]), cmd->argv, 0);
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putstr_fd(cmd->argv[0], 2);
		ft_putchar_fd('\n', 2);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		sh->last_status = status;
	}
	else
		ft_putendl_fd("minishell: fork error", 2);
}

void	executer(t_shell *sh)
{
	int		pipefd[2];
	t_cmd	*cmd;

	cmd = sh->cmd_head;
	while (cmd)
	{
		if (cmd->next)
		{
			if (pipe(pipefd) == -1)
				return (ft_putendl_fd("minishell: pipe error", 2));
			execute(sh, cmd, pipefd, 1);
			execute(sh, cmd->next, pipefd, 0);
			close(pipefd[0]);
			close(pipefd[1]);
			cmd = cmd->next;
		}
		else
		{
			execute(sh, cmd, 0, 0);
			break ;
		}
	}
}
