/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:25:19 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/24 14:20:21 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	while (n--)
	{
		c1 = *s1++;
		c2 = *s2++;
		if (!c1 && !c2)
			break ;
		if (!c1)
			return (-1);
		if (!c2)
			return (1);
		if (c1 > c2)
			return (1);
		if (c1 < c2)
			return (-1);
	}
	return (0);
}
