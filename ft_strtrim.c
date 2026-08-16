/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:14:39 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/02 13:22:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*fstr;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	str = (char *) ft_calloc((end - start + 1), sizeof(char));
	if (!str)
		return (0);
	fstr = str;
	while (start < end)
		*str++ = s1[start++];
	return (fstr);
}
