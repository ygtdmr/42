/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:26:10 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/31 18:26:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*ns;
	int			i;

	i = 0;
	ns = ft_strdup(s);
	while (*s)
	{
		ns[i] = f(i, *s++);
		i++;
	}
	return (ns);
}
