/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:45:38 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/19 19:34:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	bf[1024][BUFFER_SIZE + 1];
	char		*s;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (0);
	if (!*bf[fd] && read(fd, bf[fd], BUFFER_SIZE) == -1)
		return (0);
	s = 0;
	while (!gnl_strfnl(s) && *bf[fd])
	{
		s = gnl_strmerge(s, gnl_bftostr(bf[fd]));
		gnl_bfmv(bf[fd]);
		if (!gnl_strfnl(s) && (!*bf[fd] && read(fd, bf[fd], BUFFER_SIZE) == -1))
		{
			if (s)
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
