/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:52:14 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/19 16:32:52 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	check_enemy(char **map, int x, int y)
{
	if (map[y][x] == 'N')
	{
		map[y][x] = 'X';
		if (map[y][x + 1] == '0')
			map[y][x + 1] = 'N';
		else if (map[y][x - 1] == '0')
			map[y][x - 1] = 'N';
		else
			return (0);
	}
	return (1);
}

void	scan_map(t_slverify_path *va, char **map, int x, int y)
{
	if (map[y][x] != 'X' && map[y][x] != '1')
	{
		if (map[y][x] == 'C')
			va->cc++;
		else if (map[y][x] == 'E')
			va->ise = 1;
		else if (map[y][x] == 'P')
			va->isp = 1;
		if (map[y][x] != 'E' && map[y][x] != 'N')
			map[y][x] = 'X';
	}
	if (map[y][x] == 'E')
		return ;
	if (!check_enemy(map, x, y))
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
