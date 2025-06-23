/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:25:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/23 14:54:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executer.h"
#include "str_utils.h"
#include "env_utils.h"
#include "test/test.h"

static void	handle_sigint(int signum)
{
	ft_putchar_fd('\n', 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
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
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	sh.env = env_append(envp, 0);
	shell_loop(&sh);
	clear_env(sh.env);
	return (0);
}
