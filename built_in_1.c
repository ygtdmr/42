/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 14:54:42 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/09 10:42:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	bi_echo(int fd, char **argv)
{
	int	i;
	int	is_n;

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

void	bi_cd(int fd, t_shell *sh, t_cmd *cmd, int has_pipe)
{
	char	*oldpwd;
	int		status;

	if (has_pipe)
		return ;
	if (cmd->argv[1] && cmd->argv[2] && *cmd->argv[2])
	{
		cmd->last_status = 1 << 8;
		return (ft_putendl_fd("minishell: cd: too many arguments", 2));
	}
	oldpwd = getcwd(0, 0);
	if (cmd->argv[1] && !str_match(cmd->argv[1], "--"))
	{
		if (str_match(cmd->argv[1], "-"))
		{
			status = chdir(env_get(sh->env, "OLDPWD"));
			if (status != -1)
				ft_putendl_fd(env_get(sh->env, "OLDPWD"), fd);
		}
		else
			status = chdir(cmd->argv[1]);
	}
	else
		status = chdir(env_get(sh->env, "HOME"));
	bi_cd_after(sh, cmd, oldpwd, status);
}

void	bi_pwd(int fd)
{
	char	*cwd;

	cwd = getcwd(0, 0);
	if (cwd)
	{
		ft_putendl_fd(cwd, fd);
		free(cwd);
	}
}

void	bi_env(int *fds, t_cmd *cmd, char **env)
{
	int		i;
	char	*k;

	i = 1;
	if (cmd->argv[i])
	{
		while (cmd->argv[i] && ft_strchr(cmd->argv[i], '='))
		{
			k = env_key(cmd->argv[i]);
			env_append(&env, k, ft_strdup(ft_strchr(cmd->argv[i++], '=') + 1));
			free(k);
		}
	}
	if (cmd->argv[i])
		waitpid(run_with_env(fds, cmd->argv, env, i), &cmd->last_status, 0);
	i = 0;
	while (!cmd->argv[1] && env[i])
	{
		if (ft_strchr(env[i], '='))
			ft_putendl_fd(env[i], fds[1]);
		i++;
	}
	clear_sl(env);
}

void	bi_exit(t_shell *sh, t_cmd *cmd, int has_pipe)
{
	size_t	i;

	i = 0;
	if (cmd->argv[1])
	{
		while (1)
		{
			i += ((cmd->argv[1][i] == '-') || (cmd->argv[1][i] == '+'));
			if (!ft_isdigit(cmd->argv[1][i]))
			{
				cmd->last_status = 2 << 8;
				ft_putendl_fd("minishell: exit: numeric argument required", 2);
				return ;
			}
			if (!cmd->argv[1][++i])
				break ;
		}
		if (cmd->argv[2] && *cmd->argv[2])
		{
			cmd->last_status = 1 << 8;
			return (ft_putendl_fd("minishell: exit: too many arguments", 2));
		}
		cmd->last_status = mod256_from_str(cmd->argv[1]) << 8;
	}
	sh->exit = !has_pipe && 1;
}
