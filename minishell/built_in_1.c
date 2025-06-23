/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:54:42 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/23 16:58:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "env_utils.h"
#include "str_utils.h"

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
}

void	bi_cd(t_shell *sh, char **argv)
{
	char	*oldpwd;
	int		status;

	oldpwd = getcwd(0, 0);
	oldpwd = str_lrealloc(ft_strdup("OLDPWD="), oldpwd, ft_strlen(oldpwd), 1);
	if (argv[1])
	{
		if (str_match(argv[1], "-"))
		{
			status = chdir(env_get(sh->env, "OLDPWD"));
			if (status != -1)
				ft_putendl_fd(env_get(sh->env, "OLDPWD"), 1);
		}
		else
			status = chdir(argv[1]);
	}
	else if (env_get(sh->env, "HOME"))
		status = chdir(env_get(sh->env, "HOME"));
	if (status == -1)
		perror("minishell: cd");
	else
		sh->env = env_append(sh->env, oldpwd);
	free(oldpwd);
}

void	bi_pwd(char **argv)
{
	char	*cwd;

	cwd = getcwd(0, 0);
	if (cwd)
	{
		ft_putendl_fd(cwd, 1);
		free(cwd);
	}
}

void	bi_env(char **env)
{
	while (*env)
		ft_putendl_fd(*(env++), 1);
}
