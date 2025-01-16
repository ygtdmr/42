/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:42:36 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/04 19:40:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putf(const char *f, va_list args)
{
	if (ft_strncmp(f, "%c", 2) == 0)
		return (ft_putchr(va_arg(args, int)));
	if (ft_strncmp(f, "%s", 2) == 0)
		return (ft_putstr(va_arg(args, char *)));
	if (ft_strncmp(f, "%p", 2) == 0)
		return (ft_putptr(va_arg(args, void *)));
	if (ft_strncmp(f, "%d", 2) == 0 || ft_strncmp(f, "%i", 2) == 0)
		return (ft_putint(va_arg(args, int), 0));
	if (ft_strncmp(f, "%u", 2) == 0)
		return (ft_putbase("0123456789", va_arg(args, unsigned int), 0));
	if (ft_strncmp(f, "%x", 2) == 0)
		return (ft_putbase("0123456789abcdef", va_arg(args, unsigned int), 0));
	if (ft_strncmp(f, "%X", 2) == 0)
		return (ft_putbase("0123456789ABCDEF", va_arg(args, unsigned int), 0));
	if (ft_strncmp(f, "%%", 2) == 0)
		return (ft_putchr(37));
	return (0);
}
