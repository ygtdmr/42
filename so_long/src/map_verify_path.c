/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:52:32 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/15 15:23:16 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	scan_map(t_slva *va, char **map, int x, int y)
{
	if (map[y][x] != 'X' && map[y][x] != '1')
	{
		if (map[y][x] == 'C')
			va->cc++;
		else if (map[y][x] == 'E')
			va->ise = 1;
		else if (map[y][x] == 'P')
			va->isp = 1;
		if (map[y][x] != 'E')
			map[y][x] = 'X';
	}
	if (map[y][x] == 'E')
		return ;
	if (map[y + 1][x] != 'X' && map[y + 1][x] != '1')
		scan_map(va, map, x, y + 1);
	if (map[y - 1][x] != 'X' && map[y - 1][x] != '1')
		scan_map(va, map, x, y - 1);
	if (map[y][x + 1] != 'X' && map[y][x + 1] != '1')
		scan_map(va, map, x + 1, y);
	if (map[y][x - 1] != 'X' && map[y][x - 1] != '1')
		scan_map(va, map, x - 1, y);
}

int	map_verify_path(t_sldata *sld, char **map)
{
	t_slva	va;
	int		imh;

	ft_memset(&va, 0, sizeof(va));
	scan_map(&va, map, sld->pp.x, sld->pp.y);
	imh = 0;
	while (imh < sld->mh)
		free(map[imh++]);
	free(map);
	return (va.cc == sld->col && va.ise && va.isp);
}
