/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:45:38 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/15 17:07:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

static int	strisnl(char *s)
{
	while (s && *s)
	{
		if (*s++ == '\n')
			return (1);
	}
	return (0);
}

char *get_next_line (int fd)
{
	static char	*buffer;
	char		*fbuffer;
	char		*tmpbf;
	char		*s;

	s = 0;
	if (!buffer)
		buffer = gnl_readmem(fd);
	while (buffer && !strisnl(s))
	{
		if(!*buffer)
		{
			tmpbf = gnl_readmem(fd);
			if (tmpbf)
				{
					free(fbuffer);
					buffer = tmpbf;
					fbuffer = buffer;
				}
			else
				break ;
		}
		else
			s = gnl_line(s, *buffer++);
	}
	return (s);
}
