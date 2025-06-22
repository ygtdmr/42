/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 14:34:27 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/21 10:52:53 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_list.h"
#include "executer.h"

void	bi_export(t_shell *sh, char	**argv)
{
	int		i;
	char	**tmp_env;

	i = 1;
	while (argv[i])
	{
		tmp_env = sh->env;
		if (env_var_exists(tmp_env, argv[i]))
			sh->env = env_set(tmp_env, argv[i], 0);
		else
			sh->env = env_append(tmp_env, argv[i]);
		clear_env(tmp_env);
		i++;
	}
}

void	bi_unset(t_shell *sh, char  **argv)
{
	int		i;
	char	**tmp_env;

	i = 1;
	while (argv[i])
	{
		tmp_env = sh->env;
		sh->env = env_set(tmp_env, argv[i], 1);
		clear_env(tmp_env);
		i++;
	}
}
