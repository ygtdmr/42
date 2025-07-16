/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:42:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/14 16:28:25 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "libft/libft.h"

void	env_append(char ***env, char *key, char *val);
char	*env_get(char **env, char *key);
char	*env_key(char *src);
int		env_key_exists(char **env, char *key);
int		env_key_valid(char *src);
void	clear_env(char **env);
char	**env_dup(char **env, int clear);
char	*env_str(char *key, char *val);

#endif
