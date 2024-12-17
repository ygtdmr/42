/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:45:38 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/17 16:23:27 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

static int		strlstc(char *s, char c)
{
	while (s && s++)
	{
		if (*s == c)
			return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	bf[BUFFER_SIZE + 1];
	static int	bfi;
	int			bfl;
	char		*s;

	printf("bf=|%s|\n", bf);
	bfl = gnl_readbf(fd, bf, &bfi, 0);
	if (bfl < 1)
		return (0);
	s = 0;
	while (!strlstc(s, '\n') && bfl > 0)
	{
		if (bf[bfi] == '\n' || !bf[bfi])
		{
			if (bfl > 0)
				s = gnl_readline(s, bf, bfi + (bf[bfi] == '\n'));
			else if (bfl == -1)
			{
				free(s);
				return (0);
			}
			bfl = gnl_readbf(fd, bf, &bfi, bfl);
		}
		bfi++;
	}
	return (s);
}
