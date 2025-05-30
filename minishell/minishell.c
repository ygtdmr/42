/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:25:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/29 23:55:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "lexer.h"
#include "parser.h"
#include "test/test.h"

int	g_signum;

static void	handle_sigint(int signum)
{
	g_signum = signum;
	write(1, "\n", 1);
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
		if (!line)
		{
			write(1, "exit\n", 5);
			break ;
		}
		if (*line)
		{
			lexer(&line, sh);
			parser(sh);
			// print_tokens(sh);
			print_cmd(sh);
			clear_tok(&sh->token_head);
		}
		free(line);
	}
}

void	syntax_err(char *near)
{
	ft_putstr_fd("minishell: syntax error near unexpected token '", 2);
	if (near)
		ft_putstr_fd(near, 2);
	else
		ft_putstr_fd("newline", 2);
	ft_putstr_fd("'\n", 2);
}

int	main(int ac, char **av, char **envp)
{
	t_shell	sh;

	printf("shell_pid %d\n", getpid());
	ft_bzero(&sh, sizeof(sh));
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	sh.env_head = env_list(envp);
	shell_loop(&sh);
	clear_env_list(&sh.env_head);
	return (0);
}
