/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 00:06:10 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/16 17:13:29 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map(t_sldata *sld, int mfd)
{
	char	**map;
	int		i;
	int		il;

	i = 0;
	il = 0;
	map = malloc(sizeof(char *) * sld->mh);
	while (i < sld->mh)
	{
		il = 0;
		map[i] = get_next_line(mfd);
		while (map[i][il] && map[i][il] != '\n')
		{
			if (map[i][il] == 'P')
				sld->pp = init_p(il, i);
			else if (map[i][il] == 'E')
				sld->pe = init_p(il, i);
			il++;
		}
		i++;
	}
	return (map);
}
