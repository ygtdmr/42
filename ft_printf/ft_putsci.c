/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsci.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:51:22 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/28 21:59:51 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putsci(double dbl, int isupe)
{
	int	e;

	e = 0;
	if (dbl != 0)
	{
		while (dbl >= 10.0)
		{
			dbl /= 10.0;
			e++;
		}
		while (dbl < 1.0)
		{
			dbl *= 10.0;
			e--;
		}
	}
	return (ft_printf("%f%c%d", dbl, 'e' - (isupe * 32), e));
}
