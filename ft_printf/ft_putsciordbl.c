/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsciordbl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:08:49 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/28 21:59:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static double	power(int i, int p)
{
	int		s;
	double	r;

	if (p == 0)
		return (1);
	s = 1;
	if (p < 0)
	{
		s = -1;
		p = -p;
	}
	r = i;
	while (--p)
		r *= i;
	if (s < 0)
		r = 1 / r;
	return (r);
}

int	ft_putsciordbl(double dbl, int dfl, int isupe)
{
	double	isb;
	double	iss;
	double	absdbl;

	isb = power(10, dfl - 1);
	iss = power(10, -4);
	absdbl = dbl;
	if (absdbl < 0)
		absdbl = -absdbl;
	if (absdbl >= isb || absdbl < iss)
		return (ft_putsci(dbl, isupe));
	else
		return (ft_putldbl(dbl, 2));
}
