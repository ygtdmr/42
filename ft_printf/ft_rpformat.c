/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rpformat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 19:38:50 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/08 11:32:00 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	putf(const char *f, char *s)
{
	int	l;

	if (!s)
		return (-1);
	if (ft_ispflag(f))
		s = ft_rpflag(f, s);
	l = write(1, s, ft_strlen(s));
	free(s);
	return (l);
}

static int	putstr(const char *f, char *s)
{
	int	l;

	if (!s)
		s = "(null)";
	s = ft_strdup(s);
	if (ft_ispflag(f))
		s = ft_rpflag(f, s);
	l = write(1, s, ft_strlen(s));
	free (s);
	return (l);
}

static int	putchr(const char *f, char c)
{
	char	*s;
	int		isn;
	int		l;

	if (ft_ispflag(f))
	{
		isn = c == 0;
		if (isn)
			c = 1;
		s = ft_calloc(2, sizeof(char));
		if (!s)
			return (-1);
		*s = c;
		s = ft_rpflag(f, s);
		l = ft_strlen(s);
		if (isn)
			*ft_strchr(s, 1) = 0;
		l = write(1, s, l);
		free(s);
		return (l);
	}
	else
		return (write(1, &c, 1));
}

int	ft_rpformat(const char *f, va_list args)
{
	char	*s;
	char	type;

	s = 0;
	type = *(f + (ft_ispformat(f) - 1));
	if (type == 'c')
		return (putchr(f, va_arg(args, int)));
	else if (type == 's')
		return (putstr(f, va_arg(args, char *)));
	else if (type == 'p')
		s = ft_baseptr(va_arg(args, void *));
	else if ((type == 'd') || (type == 'i'))
		s = ft_itoa(va_arg(args, int));
	else if (type == 'u')
		s = ft_base("0123456789", va_arg(args, unsigned int));
	else if (type == 'x')
		s = ft_base("0123456789abcdef", va_arg(args, unsigned int));
	else if (type == 'X')
		s = ft_base("0123456789ABCDEF", va_arg(args, unsigned int));
	else if (type == '%')
		return (putchr(f, '%'));
	return (putf(f, s));
}
