/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:54:42 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/01 15:56:27 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "executer.h"
#include "env_utils.h"
#include "str_utils.h"

void	bi_echo(int fd, char **argv)
{
	int		i;
	int		is_n;

	i = 1;
	is_n = 0;
	if (argv[1])
		is_n = arg_is_option(argv[1], 'n');
	while (argv[i] && arg_is_option(argv[i], 'n'))
		i++;
	while (argv[i])
	{
		ft_putstr_fd(argv[i], fd);
		if (argv[++i])
			ft_putstr_fd(" ", fd);
	}
	if (!is_n)
		ft_putstr_fd("\n", fd);
}

void	bi_cd(int fd, t_shell *sh, char **argv)
{
	char	*oldpwd;
	int		status;

	if (argv[1] && argv[2] && *argv[2])
	{
		sh->last_status = 1 << 8;
		return (ft_putendl_fd("minishell: cd: too many arguments", 2));
	}
	oldpwd = getcwd(0, 0);
	if (argv[1])
	{
		if (str_match(argv[1], "-"))
		{
			status = chdir(env_get(sh->env, "OLDPWD"));
			if (status != -1)
				ft_putendl_fd(env_get(sh->env, "OLDPWD"), fd);
		}
		else
			status = chdir(argv[1]);
	}
	else
		status = chdir(env_get(sh->env, "HOME"));
	bi_cd_after(sh, argv, oldpwd, status);
}

void	bi_pwd(int fd, char **argv)
{
	char	*cwd;

	cwd = getcwd(0, 0);
	if (cwd)
	{
		ft_putendl_fd(cwd, fd);
		free(cwd);
	}
}

void	bi_env(int fd, char **env)
{
	while (*env)
		ft_putendl_fd(*(env++), fd);
}

void	bi_exit(t_shell *sh, char **argv, int has_pipe)
{
	size_t	i;

	i = 0;
	if (argv[1] && argv[2] && *argv[2])
	{
		sh->last_status = 1 << 8;
		return (ft_putendl_fd("minishell: exit: too many arguments", 2));
	}
	if (argv[1] && *argv[1])
	{
		i += ((argv[1][0] == '-') || (argv[1][0] == '+'));
		while (argv[1][i])
		{
			if (!ft_isdigit(argv[1][i++]))
			{
				sh->last_status = 2 << 8;
				return (ft_putendl_fd("minishell: exit: numeric argument required", 2));
			}
		}
		sh->last_status = ft_atoi(argv[1]) << 8;
	}
	if (!has_pipe)
		sh->exit = 1;
}
