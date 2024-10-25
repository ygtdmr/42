/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 21:37:45 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/25 13:23:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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

int	main(void)
{
	printf("result=%s\n", ft_strnstr("aaabcabcd", "abcd", 9));
	return (0);
}
