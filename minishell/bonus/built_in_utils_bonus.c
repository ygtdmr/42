/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:13:40 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/14 13:32:41 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in_bonus.h"
#include "env_utils_bonus.h"
#include "str_utils_bonus.h"

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
	char	**tmp_env;
	char	*pwd;

	pwd = getcwd(0, 0);
	pwd = str_lrealloc(ft_strdup("PWD="), pwd, ft_strlen(pwd), 1);
	oldpwd = str_lrealloc(ft_strdup("OLDPWD="), oldpwd, ft_strlen(oldpwd), 1);
	if (status == -1)
		perror("minishell: cd");
	else
	{
		tmp_env = sh->env;
		sh->env = env_append(tmp_env, oldpwd);
		clear_env(tmp_env);
		sh->env = env_append(sh->env, pwd);
	}
	cmd->last_status = (status == -1) << 8;
	free(oldpwd);
	free(pwd);
}
