/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 14:53:22 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/14 14:55:42 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run(t_shell *sh)
{
	int		i;

	i = 0;
	while (sh->prompt)
	{
		lexer(sh, &sh->prompt);
		parser(sh);
		executer(sh);
		clear_cmd(&sh->cmd_head);
		clear_tok(&sh->token_head);
		i++;
	}
}

void	non_interactive_run(t_shell *sh)
{
	char	*prompt;
	char	*line;

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

void	interactive_run(t_shell *sh)
{
	char	*line;

	sh->interactive = 1;
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
