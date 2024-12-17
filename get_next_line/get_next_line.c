/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:45:38 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/17 22:22:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 4096
#endif

char	*get_next_line(int fd)
{
	static char	bf[BUFFER_SIZE + 1];
	char		*s;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	if (!*bf && read(fd, bf, BUFFER_SIZE) == -1)
		return (0);
	s = 0;
	while (!gnl_strlc(s, '\n') && *bf)
	{
		s = gnl_strmerge(s, gnl_bftostr(bf));
		gnl_bfmv(bf);
		if ((!*bf && read(fd, bf, BUFFER_SIZE) == -1))
		{
			free(s);
			return (0);
		}
	}
	if (s && !*s)
	{
		free(s);
		return (0);
	}
	return (s);
}
