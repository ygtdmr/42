/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:17:51 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/25 13:23:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		lneedle;

	lneedle = 0;
	if (!*needle)
		return ((char *) haystack);
	while (*haystack && len--)
	{
		if (*haystack == needle[lneedle])
		{
			if (!needle[lneedle + 1])
				return ((char *)(haystack - lneedle));
			lneedle++;
		}
		else
		{
			haystack -= (lneedle - 1);
			len += (lneedle - 1);
			lneedle = 0;
			continue ;
		}
		haystack++;
	}
	return (0);
}
