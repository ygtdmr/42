/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putldbl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:43:37 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/30 14:13:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putdi(int n)
{
	int	d;
	int	l;

	l = 0;
	if (n >= 10)
		l += putdi(n / 10);
	d = 48 + (n % 10);
	return (l + ft_putchr(d));
}

static double	dblrnd(double d, int dfl)
{
	double	r;

	r = 0.5;
	while (dfl--)
		r /= 10;
	return (d + r);
}

int	ft_putldbl(long double d, int dfl)
{
	double	f;
	char	fc;
	int		di;
	int		l;

	l = 0;
	if (d < 0)
	{
		d *= -1;
		l += ft_putchr(45);
	}
	di = (int) d;
	f = dblrnd((d - di), dfl);
	l += putdi(di);
	if (dfl > 0)
		l += ft_putchr(46);
	while (dfl--)
	{
		f *= 10;
		fc = 48 + ((int) f);
		l += ft_putchr(fc);
		f -= (int)f;
	}
	return (l);
}
