/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 22:34:56 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/04 19:43:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putint(int n, int ise)
{
	int		l;

	l = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		if (ft_putchr(45) == -1)
			return (-1);
		l++;
		n *= -1;
	}
	if (n >= 10)
		ise = ft_putint(n / 10, ise);
	if (ise == -1)
		return (-1);
	l += ise;
	ise = ft_putchr(48 + n % 10);
	if (ise == -1)
		return (-1);
	return (l + ise);
}
