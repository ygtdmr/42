/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 14:13:40 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/14 17:31:48 by yidemir          ###   ########.fr       */
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
	char	*pwd;

	if (status == -1)
	{
		perror("minishell: cd");
		free(oldpwd);
	}
	else
	{
		pwd = getcwd(0, 0);
		env_append(&sh->env, ft_strdup("PWD"), pwd);
		env_append(&sh->env, ft_strdup("OLDPWD"), oldpwd);
	}
	cmd->last_status = (status == -1) << 8;
}
