/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:00:45 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/04 19:40:05 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_ispf(const char *s);
int		ft_ispfe(const char *s);
int		ft_printf(const char *f, ...);
int		ft_putf(const char *f, va_list args);
int		ft_putsci(double dbl, int isupe);
int		ft_putsciordbl(double dbl, int dfl, int isupe);
int		ft_putbase(char *b, size_t v, int ise);
int		ft_putldbl(long double d, int dfl);
int		ft_putstr(const char *s);
int		ft_putchr(char c);
int		ft_putint(int n, int ise);
int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_putptr(void *p);

#endif
