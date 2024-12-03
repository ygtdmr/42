/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:42:36 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/03 18:34:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putf_extended(const char *f, va_list args, int cl)
{
	if (ft_strncmp(f, "%n", 2) == 0)
	{
		*va_arg(args, int *) = cl;
		return (0);
	}
	if (ft_strncmp(f, "%o", 2) == 0)
		return (ft_putbase("01234567", va_arg(args, int), 0));
	if (ft_strncmp(f, "%f", 2) == 0)
		return (ft_putldbl(va_arg(args, double), 6));
	if (ft_strncmp(f, "%e", 2) == 0)
		return (ft_putsci(va_arg(args, double), 0));
	if (ft_strncmp(f, "%E", 2) == 0)
		return (ft_putsci(va_arg(args, double), 1));
	if (ft_strncmp(f, "%g", 2) == 0)
		return (ft_putsciordbl(va_arg(args, double), 6, 0));
	if (ft_strncmp(f, "%G", 2) == 0)
		return (ft_putsciordbl(va_arg(args, double), 6, 1));
	return (-1);
}

int	ft_putf(const char *f, va_list args, int cl)
{
	if (ft_strncmp(f, "%c", 2) == 0)
		return (ft_putchr(va_arg(args, int)));
	if (ft_strncmp(f, "%s", 2) == 0)
		return (ft_putstr(va_arg(args, char *)));
	if (ft_strncmp(f, "%p", 2) == 0)
		return (ft_putptr(va_arg(args, void *)));
	if (ft_strncmp(f, "%d", 2) == 0 || ft_strncmp(f, "%i", 2) == 0)
		return (ft_putint(va_arg(args, int)));
	if (ft_strncmp(f, "%u", 2) == 0)
		return (ft_putbase("0123456789", va_arg(args, unsigned int), 0));
	if (ft_strncmp(f, "%x", 2) == 0)
		return (ft_putbase("0123456789abcdef", va_arg(args, unsigned int), 0));
	if (ft_strncmp(f, "%X", 2) == 0)
		return (ft_putbase("0123456789ABCDEF", va_arg(args, unsigned int), 0));
	if (ft_strncmp(f, "%%", 2) == 0)
		return (ft_putchr(37));
	return (putf_extended(f, args, cl));
}
