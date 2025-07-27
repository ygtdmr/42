/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:34:59 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/15 08:06:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_BONUS_H
# define EXPAND_BONUS_H

# include "minishell_bonus.h"

size_t	char_len(char c, char *str);
int		is_rawchar(char c);
int		is_varchar(char c, size_t index);
int		compile_status(int status);
int		willcard_append(t_shell *sh, char **raw, char **out);
char	*expand(t_shell *sh, char *raw);

#endif
