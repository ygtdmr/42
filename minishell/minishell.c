/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:25:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/08 21:19:15 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
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
			// add_history(line);
			print_tokens(line, sh);
		}
		free(line);
	}
}

int	main(void)
{
	t_shell	sh;

	ft_bzero(&sh, sizeof(sh));
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	shell_loop(&sh);
	return (0);
}
