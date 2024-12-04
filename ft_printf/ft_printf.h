/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:00:45 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/04 22:06:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_ispf(const char *s);
int		ft_printf(const char *f, ...);
char	*ft_base(char *b, size_t v);
char	*ft_baseptr(void *p);
int		ft_renderf(const char *f, va_list args);

#endif
