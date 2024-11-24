/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdbl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:17:39 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/24 15:53:19 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	putdi(int n)
{
	int		d;
	size_t	l;

	l = 0;
	if (n >= 10)
		l += putdi(n / 10);
	d = 48 + (n % 10);
	return (l + write(1, &d, 1));
}

static double	dblrnd(double d, int dfl)
{
	double	r;

	r = 0.5;
	while (dfl--)
		r /= 10;
	return (d + r);
}

size_t	ft_putdbl(double d, int dfl)
{
	double	f;
	char	fc;
	int		di;
	size_t	l;

	l = 0;
	if (d < 0)
	{
		d *= -1;
		l += write(1, "-", 1);
	}
	di = (int) d;
	f = dblrnd((d - di), dfl);
	l += putdi(di) + write(1, ".", 1);
	while (dfl--)
	{
		f *= 10;
		fc = 48 + ((int) f);
		l += write(1, &fc, 1);
		f -= (int)f;
	}
	return (l);
}
