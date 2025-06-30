/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:25:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/29 08:42:41 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executer.h"
#include "str_utils.h"
#include "env_utils.h"
#include "test/test.h"

int	g_interactive;

static void	handle_signt(int signum)
{
	(void) signum;
	if (g_interactive)
		close(0);
	else
	{
		ft_putstr_fd("\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	shell_loop(t_shell *sh)
{
	char	*line;

	while (1)
	{
		line = readline("minishell$ ");
		if (!line || str_match(line, "exit"))
		{
			ft_putendl_fd("exit", 1);
			break ;
		}
		if (*line)
		{
			lexer(sh, &line);
			parser(sh);
			executer(sh);
			// print_cmd(sh);
			clear_cmd(&sh->cmd_head);
			clear_tok(&sh->token_head);
		}
	}
}

int	main(int ac, char **av, char **envp)
{
	t_shell	sh;

	printf("shell_pid %d\n", getpid());
	ft_bzero(&sh, sizeof(sh));
	rl_catch_signals = 0;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_signt);
	sh.env = env_append(envp, 0);
	shell_loop(&sh);
	clear_env(sh.env);
	return (0);
}
