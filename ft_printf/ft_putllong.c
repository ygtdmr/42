/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllong.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:38:32 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/30 14:04:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putllong(signed long long n)
{
	int		d;
	int		l;

	l = 0;
	if (n < 0)
	{
		l += ft_putchr(45);
		n *= -1;
	}
	if (n >= 10)
		l += ft_putllong(n / 10);
	d = 48 + (n % 10);
	return (l + ft_putchr(d));
}
