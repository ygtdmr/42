/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:25:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/14 17:24:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include "lexer_bonus.h"
#include "parser_bonus.h"
#include "executer_bonus.h"
#include "expand_bonus.h"
#include "str_utils_bonus.h"
#include "env_utils_bonus.h"
#include "../get_next_line/get_next_line.h"
#include ".test/test_bonus.h"

int	g_running;

static void	handle_signt(int signum)
{
	(void) signum;
	if (g_running)
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
	char	**lines;
	size_t	i;

	i = 0;
	if (!line)
		return ;
	lines = ft_split(line, '\n');
	while (lines[i])
	{
		lexer(sh, lines + i);
		parser(sh);
		// executer(sh);
		// print_tokens(sh);
		print_cmd(sh);
		clear_cmd(&sh->cmd_head);
		clear_tok(&sh->token_head);
		i++;
	}
	free(lines);
	free(line);
}

static void	shell_loop(t_shell *sh)
{
	char	*line;

	while (!sh->exit)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		if (*line)
		{
			add_history(line);
			run(sh, line);
		}
	}
	ft_putendl_fd("exit", 1);
}

static char	*read_line(void)
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

	(void) ac;
	(void) av;
	rl_catch_signals = 0;
	ft_bzero(&sh, sizeof(sh));
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_signt);
	sh.env = env_append(envp, 0);
	if (isatty(0))
		shell_loop(&sh);
	else
		run(&sh, read_line());
	clear_env(sh.env);
	return (compile_status(sh.last_status));
}
