/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:34:27 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/30 12:18:13 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "env_utils.h"

void	bi_export(t_shell *sh, char	**argv)
{
	int		i;
	char	**tmp_env;

	i = 1;
	while (argv[i])
	{
		if (!env_key_valid(argv[i]))
		{
			ft_putstr_fd("minishell: export: ", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putendl_fd(": bad variable name", 2);
			break ;
		}
		tmp_env = sh->env;
		if (env_key_exists(tmp_env, argv[i]))
			sh->env = env_set(tmp_env, argv[i], 0);
		else
			sh->env = env_append(tmp_env, argv[i]);
		clear_env(tmp_env);
		i++;
	}
}

void	bi_unset(t_shell *sh, char **argv)
{
	int		i;
	char	**tmp_env;

	i = 1;
	while (argv[i])
	{
		if (!env_key_valid(argv[i]))
		{
			ft_putstr_fd("minishell: unset: ", 2);
			ft_putstr_fd(argv[i], 2);
			ft_putendl_fd(": bad variable name", 2);
			break ;
		}
		tmp_env = sh->env;
		if (env_key_exists(tmp_env, argv[i]))
		{
			sh->env = env_set(tmp_env, argv[i], 1);
			clear_env(tmp_env);
		}
		i++;
	}
}
