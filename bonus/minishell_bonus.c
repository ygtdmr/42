/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 13:25:48 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/14 15:03:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	g_running;

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

void	set_running(int val)
{
	g_running = val;
}

int	main(int ac, char **av, char **envp)
{
	t_shell	sh;

	(void)ac;
	(void)av;
	ft_bzero(&sh, sizeof(sh));
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_signt);
	sh.env = env_dup(envp, 0);
	if (env_get(sh.env, "SHLVL"))
		env_append(&sh.env, "SHLVL", \
ft_itoa(ft_atoi(env_get(sh.env, "SHLVL")) + 1));
	else
		env_append(&sh.env, "SHLVL", ft_strdup("1"));
	env_append(&sh.env, "PWD", getcwd(0, 0));
	if (isatty(0))
		interactive_run(&sh);
	else
		non_interactive_run(&sh);
	clear_sl(sh.env);
	rl_clear_history();
	return (compile_status(sh.last_status));
}
