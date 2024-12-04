/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_baseptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:04:56 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/04 23:49:45 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_baseptr(void *p)
{
	char	*tmp;
	char	*s;

	if (p)
		tmp = ft_base("0123456789abcdef", (size_t) p);
	else
		tmp = ft_strdup("0");
	s = ft_strjoin("0x", tmp);
	free(tmp);
	return (s);
}
