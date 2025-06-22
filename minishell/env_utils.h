/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:42:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/22 16:28:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "libft/libft.h"

char	**env_append(char **env, char *src);
char	**env_set(char **env, char *src, int unset);
int		env_var_exists(char **env, char *src);
void	clear_env(char **env);

#endif
