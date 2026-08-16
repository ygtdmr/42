/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:13:40 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/05 11:56:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	is_bi(char *file)
{
	if (!file)
		return (0);
	return (str_match(file, "echo") || \
str_match(file, "cd") || \
str_match(file, "pwd") || \
str_match(file, "export") || \
str_match(file, "unset") || \
str_match(file, "env") || \
str_match(file, "exit"));
}

int	arg_is_option(char *arg, char option)
{
	if (*arg != '-')
		return (0);
	else
		arg++;
	if (!*arg)
		return (0);
	while (*arg == option)
		arg++;
	return (!*arg);
}

void	bi_cd_after(t_shell *sh, t_cmd *cmd, char *oldpwd, int status)
{
	char	*pwd;

	if (status == -1)
	{
		perror("minishell: cd");
		free(oldpwd);
	}
	else
	{
		pwd = getcwd(0, 0);
		env_append(&sh->env, "PWD", pwd);
		env_append(&sh->env, "OLDPWD", oldpwd);
	}
	cmd->last_status = (status == -1) << 8;
}

int	mod256_from_str(char *s)
{
	int		sign;
	long	result;

	sign = 1;
	while (*s == '-' || *s == '+')
	{
		if (*s++ == '-')
			sign = -sign;
	}
	result = 0;
	while (*s)
		result = (result * 10 + (*s++ - '0')) % 256;
	return (result * sign);
}

pid_t	run_with_env(int *fds, char **argv, char **env, int argv_i)
{
	pid_t	pid;
	int		noenv;

	noenv = arg_is_option(argv[1], 'i');
	argv += noenv;
	pid = fork();
	if (pid == 0)
	{
		if (fds[0] > 0)
		{
			dup2(fds[0], 0);
			close(fds[0]);
		}
		if (fds[1] > 1)
		{
			dup2(fds[1], 1);
			close(fds[1]);
		}
		do_exec(argv[argv_i], argv + argv_i, env, noenv);
	}
	else if (pid == -1)
		perror("minishell: fork");
	return (pid);
}
