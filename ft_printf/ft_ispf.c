/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 23:46:31 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/24 14:20:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_ispf(const char *s)
{
	char	c;

	c = *s;
	if (c == 37)
		s++;
	else
		return (0);
	if (
		ft_strncmp(s, "ld", 2) || ft_strncmp(s, "li", 2) || \
		ft_strncmp(s, "lu", 2) || ft_strncmp(s, "Lf", 2)
	)
		return (2);
	if (
		ft_strncmp(s, "lld", 3) || ft_strncmp(s, "lli", 3) || \
		ft_strncmp(s, "llu", 3)
	)
		return (3);
	return (
		c == 'd' || c == 'i' || c == 'u' || c == 'f' || \
		c == 'e' || c == 'E' || c == 'g' || c == 'G' || \
		c == 'c' || c == 'c' || c == 'p' || c == 'n' || \
		c == 'x' || c == 'X' || c == 'o' || c == '%'
	);
}
