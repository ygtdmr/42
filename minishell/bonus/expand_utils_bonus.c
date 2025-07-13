/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:35:16 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/13 18:06:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_bonus.h"
#include "str_utils_bonus.h"

size_t	char_len(char c, char *str)
{
	size_t	length;

	length = 0;
	while (str && *str)
		length += (*str++ == c);
	return (length);
}

int	is_rawchar(char c)
{
	return (c != '\'' && \
c != '\"' && \
c != '$'
	);
}

int	is_varchar(char c, size_t index)
{
	if (index == 0)
		return (ft_isalpha(c) || c == '_');
	else
		return (ft_isalnum(c) || c == '_');
}

int	compile_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (128 + WTERMSIG(status));
	else if (WIFSTOPPED(status))
		return (128 + WSTOPSIG(status));
	return (1);
}
