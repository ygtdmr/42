/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:48:01 by yigit             #+#    #+#             */
/*   Updated: 2024/11/24 17:21:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_ispf(const char *s);
int		ft_ispfe(const char *s);
size_t	ft_printf(const char *f, ...);
size_t	ft_putbase(char *b, size_t v);
size_t	ft_putdbl(double d, int dfl);
size_t	ft_putf(const char *f, va_list args);
size_t	ft_putstr(const char *s);
size_t	ft_putchr(char c);
size_t	ft_putint(int n);

size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
