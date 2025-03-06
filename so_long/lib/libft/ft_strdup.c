/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:31:47 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/02 13:47:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*sc;
	size_t	lsc;

	lsc = ft_strlen(s1);
	sc = malloc((lsc + 1) * sizeof(char));
	if (!sc)
		return (0);
	while (*s1 != 0)
		*sc++ = *s1++;
	*sc = 0;
	return (sc - lsc);
}
