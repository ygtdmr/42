/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:25:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/29 04:59:14 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".test/test.h"
#include "minishell.h"

int			g_running;

static void	handle_signt(int signum)
{
	(void)signum;
	ft_putstr_fd("\n", 1);
	if (!g_running)
	{
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	run(t_shell *sh)
{
	int		i;

	i = 0;
	while (sh->prompt)
	{
		lexer(sh, &sh->prompt);
		parser(sh);
		executer(sh);
		// print_tokens(sh);
		// print_cmd(sh);
		clear_cmd(&sh->cmd_head);
		clear_tok(&sh->token_head);
		i++;
	}
}

static void non_interactive_run(t_shell *sh)
{
	char	*prompt;
	char 	*line;

	prompt = 0;
	line = get_next_line(0);
	while (line)
	{
		prompt = str_lrealloc(prompt, line, strlen(line), 1);
		line = get_next_line(0);
	}
	sh->prompt = prompt;
	run(sh);
}

static void	interactive_run(t_shell *sh)
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
			sh->prompt = line;
			run(sh);
		}
	}
	ft_putendl_fd("exit", 1);
}

int	main(int ac, char **av, char **envp)
{
	t_shell	sh;

	(void)ac;
	(void)av;
	printf("pid: %d\n", getpid());
	ft_bzero(&sh, sizeof(sh));
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_signt);
	sh.env = env_dup(envp, 0);
	if (isatty(0))
		interactive_run(&sh);
	else
		non_interactive_run(&sh);
	clear_env(sh.env);
	rl_clear_history();
	return (compile_status(sh.last_status));
}
