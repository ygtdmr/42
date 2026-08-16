/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 18:26:10 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/02 13:44:34 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*ns;
	int			i;

	if (!s)
		return (0);
	i = 0;
	ns = ft_strdup(s);
	if (!ns)
		return (0);
	while (*s != 0)
	{
		ns[i] = f(i, *s++);
		i++;
	}
	return (ns);
}
