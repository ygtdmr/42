/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:45:38 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/15 17:46:37 by yidemir          ###   ########.fr       */
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
	static char	*fbf;
	char		*s;

	s = 0;
	if (!buffer)
		buffer = gnl_readmem(fd);
	if (!fbf)
		fbf = buffer;
	while (buffer && !strisnl(s))
	{
		if(!*buffer)
		{
			free(fbf);
			buffer = gnl_readmem(fd);
			if (!buffer)
				break ;
			fbf = buffer;
		}
		else
			s = gnl_line(s, *buffer++);
	}
	return (s);
}
