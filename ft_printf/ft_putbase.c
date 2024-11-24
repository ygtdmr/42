/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:18:09 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/24 17:57:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_putbase(char *b, size_t v)
{
	size_t	l;
	int		lb;

	l = 0;
	lb = ft_strlen(b);
	if (v >= 10)
		l += ft_putbase(b, v / lb);
	if (v == 0 && l == 0)
		return (0);
	return (l + ft_putchr(b[v % lb]));
}
