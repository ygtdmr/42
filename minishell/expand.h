/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:34:59 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/12 07:38:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "minishell.h"

size_t	char_len(char c, char *str);
int		is_rawchar(char c);
int		is_varchar(char c, size_t index);
int		compile_status(int status);
char	*expand(t_shell *sh, char *raw);

#endif
