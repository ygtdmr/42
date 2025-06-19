/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:54:42 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/19 18:01:28 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "lexer.h"
#include "parser.h"

void	bi_echo(char **argv)
{
	int		i;
	int		is_n;

	is_n = (argv[1] && str_match(argv[1], "-n"));
	i = 1 + is_n;
	while (argv[i])
	{
		ft_putstr_fd(argv[i], 1);
		if (argv[++i])
			write(1, " ", 1);
	}
	if (!is_n)
		write(1, "\n", 1);
	exit(0);
}

void	bi_cd(char **argv)
{
	if (argv[1])
		chdir(argv[1]);
	else if(getenv("HOME"))
		chdir(getenv("HOME"));
}

void	bi_pwd(char **argv)
{
	char	*cwd;

	cwd = getcwd(0,0);
	if (cwd)
	{
		ft_putendl_fd(cwd, 1);
		free(cwd);
	}
	exit(0);
}

void	bi_exit(t_shell *sh)
{
	clear_cmd(&sh->cmd_head);
	clear_tok(&sh->token_head);
	exit(0);
}
