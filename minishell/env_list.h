/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:42:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/20 14:50:44 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_LIST_H
# define ENV_LIST_H

#include "minishell.h"

char	**env_append(char **env, char *src);
char	**env_set(char **env, char *src, int unset);
int		env_var_exists(char **env, char *src);
void	clear_env(char **env);

#endif
