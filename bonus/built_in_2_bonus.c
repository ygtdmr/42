/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:34:27 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/11 04:45:20 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static char	**sorting_alphabet(char **env)
{
	int		i;
	int		j;
	int		env_count;
	char	**arr;

	env_count = 0;
	while (env[env_count])
		env_count++;
	arr = env_dup(env, 0);
	if (!arr)
		return (0);
	i = -1;
	while (++i < env_count - 1)
	{
		j = -1;
		while (++j < env_count - i - 1)
		{
			if (ft_strncmp(arr[j], arr[j + 1], ft_strlen(arr[j])) > 0)
				str_swap(&arr[j], &arr[j + 1]);
		}
	}
	return (arr);
}

static void	print_env_entry(int fd, char *env)
{
	int		i;
	char	*key;

	i = 0;
	if (!ft_strchr(env, '='))
	{
		key = env_key(env);
		ft_putstr_fd(key, fd);
		ft_putchar_fd('\n', fd);
		free(key);
		return ;
	}
	while (env[i] != '=')
		ft_putchar_fd(env[i++], fd);
	ft_putstr_fd("=\"", fd);
	i++;
	while (env[i])
		ft_putchar_fd(env[i++], fd);
	ft_putendl_fd("\"", fd);
}

static void	print_export_vars(int fd, t_shell *sh)
{
	char	**env;
	char	**sorted;

	sorted = sorting_alphabet(sh->env);
	if (!(sorted))
		return ;
	env = sorted;
	while (*env)
	{
		if (!ft_strnstr(*env, "_=", 2))
		{
			ft_putstr_fd("declare -x ", fd);
			print_env_entry(fd, *env);
		}
		env++;
	}
	clear_sl(sorted);
}

void	bi_export(int fd, t_shell *sh, t_cmd *cmd, int has_pipe)
{
	int		i;
	char	*k;
	char	*value;

	if (!cmd->argv[1])
		return (print_export_vars(fd, sh));
	i = 0;
	while (!has_pipe && cmd->argv[++i])
	{
		cmd->last_status = env_key_validate(cmd->argv[i], "export: ", 0) << 8;
		if (cmd->last_status)
			return ;
		if (ft_strchr(cmd->argv[i], '='))
		{
			k = env_key(cmd->argv[i]);
			value = ft_strdup(ft_strchr(cmd->argv[i], '=') + 1);
			if (env_get(sh->env, k) && ft_strchr(cmd->argv[i], '=')[-1] == '+')
				value = str_realloc(ft_strdup(env_get(sh->env, k)), value, 1);
			env_append(&sh->env, k, value);
			free(k);
		}
		else
			env_append(&sh->env, cmd->argv[i], 0);
	}
	update_cmd_argv(sh, cmd->next);
}

void	bi_unset(t_shell *sh, t_cmd *cmd, int has_pipe)
{
	int		i;
	char	*key;

	if (has_pipe)
		return ;
	i = 0;
	while (cmd->argv[++i])
	{
		cmd->last_status = env_key_validate(cmd->argv[i], "unset: ", 1) << 8;
		if (ft_strchr(cmd->argv[i], ';'))
		{
			ft_putendl_fd("minishell: unset: semicolon not support", 2);
			cmd->last_status = 127 << 8;
		}
		if (cmd->last_status)
			return ;
		key = env_key(cmd->argv[i]);
		if (env_key_exists(sh->env, key))
			env_append(&sh->env, key, 0);
		free(key);
	}
	update_cmd_argv(sh, cmd->next);
}
