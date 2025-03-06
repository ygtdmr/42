/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:06:10 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/04 15:30:23 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	**get_map(t_sldata *sld, char *mpath)
{
	char	**map;
	char	*line;
	int		fd_path;
	int		i;
	int		il;

	i = 0;
	il = 0;
	map = malloc(sizeof(char *) * sld->mh);
	fd_path = open(mpath, O_RDONLY);
	while(i < sld->mh)
	{
		line = get_next_line(fd_path);
		map[i] = ft_strdup(line);
		while (map[i][il] && map[i][il] != '\n')
		{
			if (map[i][il] == 'P')
				sld->player = &map[i][il];
			il++;
		}
		i++;
	}
	return (map);
}
