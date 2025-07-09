/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:34:59 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/09 14:05:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_BONUS_H
# define EXPAND_BONUS_H

# include "minishell_bonus.h"

size_t	char_len(char c, char *str);
int		is_varchar(char c, size_t index);
int		compile_status(int status);
void	custom_append(char **dest, char *src, int src_free);
char	*expand(t_shell *sh, char *raw);

#endif
