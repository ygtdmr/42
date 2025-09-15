/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:30:05 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/14 15:57:59 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	scan_map_line(t_cub3d *cub3d, char *line, int end)
{
	size_t	i;

	i = 0;
	if (str_setonly(line, " 01NSEW\n"))
	{
		if (end)
		{
			if (!str_setonly(line, "1\n"))
				exit_err(cub3d, "invalid map: map must surround with wall", 0);
			return ;
		}
		while (line[i] && line[i] != '\n')
		{
			if ((!i || (!line[i + 1] || line[i + 1] == '\n')) && line[i] != '1')
				exit_err(cub3d, "invalid map: map must surround with wall", 0);
			i++;
		}
	}
	else
		exit_err(cub3d, "invalid map: invalid char", line + i);
}

void	scan_map_floodfill(t_cub3d *cub3d, char **dup, size_t x, size_t y)
{
	if (dup[y][x] == 'N' || dup[y][x] == 'S' || \
dup[y][x] == 'E' || dup[y][x] == 'W')
	{
		if (cub3d->player.face)
			exit_err(cub3d, "invalid map: player already defined.", 0);
		cub3d->player.face = dup[y][x];
		cub3d->player.x = x;
		cub3d->player.y = y;
	}
	else if (!dup[y][x] || dup[y][x] == ' ')
		exit_err(cub3d, "invalid map: map must surround with wall", 0);
	dup[y][x] = 'X';
	if (dup[y][x + 1] != '1' && dup[y][x + 1] != 'X')
		scan_map_floodfill(cub3d, dup, x + 1, y);
	if (dup[y][x - 1] != '1' && dup[y][x - 1] != 'X')
		scan_map_floodfill(cub3d, dup, x - 1, y);
	if (dup[y + 1][x] != '1' && dup[y + 1][x] != 'X')
		scan_map_floodfill(cub3d, dup, x, y + 1);
	if (dup[y - 1][x] != '1' && dup[y - 1][x] != 'X')
		scan_map_floodfill(cub3d, dup, x, y - 1);
}
