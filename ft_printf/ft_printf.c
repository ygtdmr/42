/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:09:27 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/04 19:30:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *f, ...)
{
	va_list	args;
	int		l;
	int		ispf;
	int		eorl;

	l = 0;
	va_start(args, f);
	while (*f)
	{
		ispf = ft_ispf(f);
		if (ispf)
		{
			eorl = ft_putf(f, args);
			f += (ispf + 1);
		}
		else
			eorl = ft_putchr(*f++);
		if (eorl == -1)
			return (va_end(args), -1);
		else
			l += eorl;
	}
	return (va_end(args), l);
}
