/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_renderf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:42:36 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/05 00:08:46 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putstr(char *s, int sl)
{
	int	l;

	if (s)
	{
		if (!sl)
			sl = ft_strlen(s);
		l = write(1, s, sl);
		free(s);
		return (l);
	}
	else
		return (-1);
}

static char	*strf(char *s)
{
	if (!s)
		s = "(null)";
	return (ft_strdup(s));
}

static int	putchr(char c)
{
	char	*s;

	s = malloc(1 * sizeof(char));
	if (!s)
		return (-1);
	*s = c;
	return (putstr(s, 1));
}

int	ft_renderf(const char *f, va_list args)
{
	char	*s;

	s = 0;
	if (ft_strncmp(f, "%c", 2) == 0)
		return (putchr(va_arg(args, int)));
	else if (ft_strncmp(f, "%s", 2) == 0)
		s = strf(va_arg(args, char *));
	else if (ft_strncmp(f, "%p", 2) == 0)
		s = ft_baseptr(va_arg(args, void *));
	else if (ft_strncmp(f, "%d", 2) == 0 || ft_strncmp(f, "%i", 2) == 0)
		s = ft_itoa(va_arg(args, int));
	else if (ft_strncmp(f, "%u", 2) == 0)
		s = ft_base("0123456789", va_arg(args, unsigned int));
	else if (ft_strncmp(f, "%x", 2) == 0)
		s = ft_base("0123456789abcdef", va_arg(args, unsigned int));
	else if (ft_strncmp(f, "%X", 2) == 0)
		s = ft_base("0123456789ABCDEF", va_arg(args, unsigned int));
	else if (ft_strncmp(f, "%%", 2) == 0)
		return (putchr('%'));
	return (putstr(s, 0));
}
