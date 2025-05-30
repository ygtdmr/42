/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:34:59 by yidemir           #+#    #+#             */
/*   Updated: 2025/05/30 21:35:00 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "minishell.h"

size_t	char_len(char c, char *str);
int		is_varchar(char c, size_t index);
char	*str_lrealloc(char *dest, char *src, size_t length);
char	*expand(char *raw, t_shell *sh);

#endif
