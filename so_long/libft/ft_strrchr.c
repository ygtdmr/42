/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:32:15 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/01 20:46:56 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*ls;
	char	ch;

	ls = 0;
	ch = (char) c;
	while (*s != 0)
	{
		if (*s == ch)
			ls = ((char *)s);
		s++;
	}
	if (ch == 0)
		return ((char *) s);
	return (ls);
}
