/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 22:00:45 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/06 20:16:54 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_pflag
{
	int	zero;
	int	plus;
	int	minus;
	int	space;
	int	hash;
	int	width;
	int	precision;
	int	zerominus;
}	t_pflag;

int		ft_ispformat(const char *s);
int		ft_ispflag(const char *s);
int		ft_printf(const char *f, ...);
char	*ft_base(char *b, size_t v);
char	*ft_baseptr(void *p);
int		ft_rpformat(const char *f, va_list args);
char	*ft_rpflag(const char *f, char *s);
char	*ft_strjcf(char c, char *s2, int end);
t_pflag	ft_getpflag(const char *f);

#endif
