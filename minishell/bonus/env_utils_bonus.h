/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:42:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/09 14:06:08 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_BONUS_H
# define ENV_UTILS_BONUS_H

# include "../libft/libft.h"

char	**env_append(char **env, char *src);
char	**env_set(char **env, char *src, int unset);
char	*env_get(char **env, char *key);
char	*env_key(char *src);
int		env_key_exists(char **env, char *src);
int		env_key_valid(char *src);
void	clear_env(char **env);

#endif
