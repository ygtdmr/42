/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 20:18:09 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/03 18:42:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putbase(char *b, size_t v, int ise)
{
	int		l;
	size_t	lb;

	l = 0;
	lb = ft_strlen(b);
	if (v >= lb && ise == 0)
		ise = ft_putbase(b, v / lb, ise);
	if (ise == -1)
		return (-1);
	l += ise;
	ise = ft_putchr(b[v % lb]);
	if (ise == -1)
		return (-1);
	return (l + ise);
}
