/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 00:36:14 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/24 13:29:42 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == 0 || src == 0)
		return (dst);
	while (len--)
		((char *) dst)[len] = ((char *) src)[len];
	return (dst);
}

int	main(void)
{
	char	str[20];

	strcpy(str, "abcdefg");
	printf("start: %s\n", str);

	memmove(&str[2], str, 5);
	printf("memmove after: %s\n", str);

	strcpy(str, "abcdefg");

	ft_memmove(&str[2], str, 5);
	printf("ft_memmove after: %s\n", str);
	return (0);
}
