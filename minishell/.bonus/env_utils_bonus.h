/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:42:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/14 17:30:54 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_BONUS_H
# define ENV_UTILS_BONUS_H

# include "../libft/libft.h"

void	env_append(char ***env, char *key, char *val);
char	*env_get(char **env, char *key);
char	*env_key(char *src);
int		env_key_exists(char **env, char *key);
int		env_key_valid(char *src);
void	clear_env(char **env);
char	**env_dup(char **env, int clear);
char	*env_str(char *key, char *val);

#endif
