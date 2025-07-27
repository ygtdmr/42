/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:34:27 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/27 03:12:59 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "env_utils.h"
#include "executer.h"
#include "str_utils.h"

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
		return (NULL);
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
	clear_env(sorted);
}

void	bi_export(int fd, t_shell *sh, t_cmd *cmd, int has_pipe)
{
	int		i;
	char	*key;
	char	*value;

	if (!cmd->argv[1])
		return (print_export_vars(fd, sh));
	i = 1;
	while (!has_pipe && cmd->argv[i])
	{
		if (!env_key_valid(cmd->argv[i]))
			return (ft_putstr_fd("minishell: export: ", 2),
				ft_putstr_fd(cmd->argv[i], 2),
				ft_putendl_fd(": not a valid identifier", 2),
				cmd->last_status = 1 << 8, (void)0);
		if (ft_strchr(cmd->argv[i], '='))
		{
			key = env_key(cmd->argv[i]);
			value = ft_strchr(cmd->argv[i], '=') + 1;
			env_append(&sh->env, key, ft_strdup(value));
			free(key);
		}
		else
			env_append(&sh->env, cmd->argv[i], NULL);
		i++;
	}
}

void	bi_unset(t_shell *sh, t_cmd *cmd, int has_pipe)
{
	int		i;
	char	*key;

	if (has_pipe)
		return ;
	i = 1;
	while (cmd->argv[i])
	{
		if (!env_key_valid(cmd->argv[i]))
		{
			ft_putstr_fd("minishell: unset: ", 2);
			ft_putstr_fd(cmd->argv[i], 2);
			ft_putendl_fd(": not a valid identifier", 2);
			cmd->last_status = 1 << 8;
			break ;
		}
		key = env_key(cmd->argv[i]);
		if (env_key_exists(sh->env, key))
			env_append(&sh->env, key, 0);
		free(key);
		i++;
	}
}
