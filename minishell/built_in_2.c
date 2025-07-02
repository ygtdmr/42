/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:34:27 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/02 16:22:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"
#include "executer.h"
#include "env_utils.h"

void	bi_export(t_shell *sh, t_cmd *cmd, int has_pipe)
{
	int		i;
	char	**tmp_env;

	if (has_pipe)
		return ;
	i = 1;
	while (cmd->argv[i])
	{
		if (!env_key_valid(cmd->argv[i]))
		{
			ft_putstr_fd("minishell: export: ", 2);
			ft_putstr_fd(cmd->argv[i], 2);
			ft_putendl_fd(": not a valid identifier", 2);
			cmd->last_status = 1 << 8;
			break ;
		}
		tmp_env = sh->env;
		if (env_key_exists(tmp_env, cmd->argv[i]))
			sh->env = env_set(tmp_env, cmd->argv[i], 0);
		else
			sh->env = env_append(tmp_env, cmd->argv[i]);
		clear_env(tmp_env);
		i++;
	}
}

void	bi_unset(t_shell *sh, t_cmd *cmd, int has_pipe)
{
	int		i;
	char	**tmp_env;

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
		tmp_env = sh->env;
		if (env_key_exists(tmp_env, cmd->argv[i]))
		{
			sh->env = env_set(tmp_env, cmd->argv[i], 1);
			clear_env(tmp_env);
		}
		i++;
	}
}
