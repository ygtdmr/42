/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 06:36:04 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/04 06:52:27 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	str_swap(char **x, char **y)
{
	char	*tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	is_varchar(char *s, size_t i)
{
	if (!i)
		return (ft_isalpha(s[i]) || s[i] == '_');
	else
		return (ft_isalnum(s[i]) || s[i] == '_');
}
