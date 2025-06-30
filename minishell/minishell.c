/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:25:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/30 16:47:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "executer.h"
#include "str_utils.h"
#include "env_utils.h"
#include "get_next_line/get_next_line.h"

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

static void	run(t_shell *sh, char *line)
{
	lexer(sh, &line);
	parser(sh);
	executer(sh);
	clear_cmd(&sh->cmd_head);
	clear_tok(&sh->token_head);
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
			add_history(line);
			run(sh, line);	
		}
	}
}

static char	*read_pipe(void)
{
	char	*line;
	char	*tmp;

	line = 0;
	tmp = get_next_line(0);
	while (tmp)
	{
		line = str_lrealloc(line, tmp, ft_strlen(tmp), 1);
		tmp = get_next_line(0);
	}
	return (line);
}

int	main(int ac, char **av, char **envp)
{
	t_shell	sh;
	char	*line_pipe;

	rl_catch_signals = 0;
	ft_bzero(&sh, sizeof(sh));
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_signt);
	sh.env = env_append(envp, 0);
	if (isatty(0))
		shell_loop(&sh);
	else
	{
		line_pipe = read_pipe();
		if (line_pipe)
			run(&sh, line_pipe);
	}
	clear_env(sh.env);
	return (0);
}
