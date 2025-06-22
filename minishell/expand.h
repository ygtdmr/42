/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:34:59 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/22 18:22:41 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_H
# define EXPAND_H

# include "minishell.h"

size_t	char_len(char c, char *str);
int		is_varchar(char c, size_t index);
int		compile_status(int status);
char	*expand(char *raw, t_shell *sh);

#endif
