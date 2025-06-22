/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:35:16 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/22 16:15:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand.h"
#include "lexer.h"

size_t	char_len(char c, char *str)
{
	size_t	length;

	length = 0;
	while (str && *str)
		length += (*str++ == c);
	return (length);
}

int	is_varchar(char c, size_t index)
{
	if (index == 0)
		return (ft_isalpha(c) || c == '_');
	else
		return (ft_isalnum(c) || c == '_');
}
