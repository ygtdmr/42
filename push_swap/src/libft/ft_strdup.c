/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:31:47 by yidemir           #+#    #+#             */
/*   Updated: 2025/02/17 20:51:19 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

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
