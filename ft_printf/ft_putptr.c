/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:04:56 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/03 21:54:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *p)
{
	int	l;

	l = ft_putstr("0x");
	if (l == -1)
		return (-1);
	if (p)
		l += ft_putbase("0123456789abcdef", (size_t) p, 0);
	else
		l += ft_putchr('0');
	return (l);
}
