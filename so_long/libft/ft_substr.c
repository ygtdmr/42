/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:16:38 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/25 22:43:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	flen;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return ((char *) ft_calloc(1, sizeof(char)));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	flen = len;
	ss = (char *) ft_calloc(len + 1, sizeof(char));
	if (!ss)
		return (0);
	s += start;
	while (*s && len)
	{
		*ss++ = *s++;
		len--;
	}
	return (ss - (flen - len));
}
