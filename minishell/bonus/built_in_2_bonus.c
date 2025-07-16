/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:34:27 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/14 17:32:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in_bonus.h"
#include "executer_bonus.h"
#include "env_utils_bonus.h"

static void	print_export_vars(int fd, t_shell *sh)
{
	int		i;
	char	**env;

	env = sh->env;
	while (*env)
	{
		i = 0;
		if (ft_strnstr(*env, "_=", 2))
		{
			env++;
			continue ;
		}
		ft_putstr_fd("declare -x ", fd);
		while ((*env)[i] != '=')
			ft_putchar_fd((*env)[i++], fd);
		ft_putstr_fd("=\"", fd);
		i++;
		while ((*env)[i])
			ft_putchar_fd((*env)[i++], fd);
		ft_putendl_fd("\"", fd);
		env++;
	}
}

void	bi_export(int fd, t_shell *sh, t_cmd *cmd, int has_pipe)
{
	int		i;
	char	*key;

	if (!cmd->argv[1])
		print_export_vars(fd, sh);
	i = 1;
	while (!has_pipe && cmd->argv[i])
	{
		if (!env_key_valid(cmd->argv[i]))
		{
			ft_putstr_fd("minishell: export: ", 2);
			ft_putstr_fd(cmd->argv[i], 2);
			ft_putendl_fd(": not a valid identifier", 2);
			cmd->last_status = 1 << 8;
			break ;
		}
		if (ft_strchr(cmd->argv[i], '='))
		{
			key = env_key(cmd->argv[i]);
			env_append(&sh->env, key, ft_strdup(ft_strchr(cmd->argv[i], '=') + 1));
		}
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
