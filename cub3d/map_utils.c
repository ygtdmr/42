/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:59:04 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/24 07:40:18 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_content_err(t_cub3d *cub3d, char *str)
{
	clear_sl(cub3d->map->tmp);
	cub3d->map->tmp = 0;
	exit_err(cub3d, str, 0);
}

static void	scan_content_fill(t_cub3d *cub3d, char **dup, size_t x, size_t y)
{
	if (!(x && y) || !dup[y][x] || !dup[y + 1] || dup[y][x] == ' ')
		map_content_err(cub3d, "invalid map: map must surround with wall");
	else if (dup[y][x] == 'N' || dup[y][x] == 'S' || \
dup[y][x] == 'E' || dup[y][x] == 'W')
	{
		if (cub3d->player.dir)
			map_content_err(cub3d, "invalid map: detected too many players");
		cub3d->player.dir = dup[y][x];
		cub3d->player.x = x;
		cub3d->player.y = y;
		init_cam(&cub3d->player);
	}
	dup[y][x] = 'X';
	if (dup[y][x + 1] != '1' && dup[y][x + 1] != 'X')
		scan_content_fill(cub3d, dup, x + 1, y);
	if (dup[y][x - 1] != '1' && dup[y][x - 1] != 'X')
		scan_content_fill(cub3d, dup, x - 1, y);
	if (dup[y + 1][x] != '1' && dup[y + 1][x] != 'X')
		scan_content_fill(cub3d, dup, x, y + 1);
	if (dup[y - 1][x] != '1' && dup[y - 1][x] != 'X')
		scan_content_fill(cub3d, dup, x, y - 1);
}

void	scan_map_content(t_cub3d *cub3d, char **dup)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	while (dup[y])
	{
		x = 0;
		while (dup[y][x])
		{
			if (dup[y][x] != '1' && dup[y][x] != ' ' && \
dup[y][x] != '\n' && dup[y][x] != 'X')
			{
				scan_content_fill(cub3d, dup, x, y);
				y = 0;
				break ;
			}
			x++;
		}
		y++;
	}
	if (!cub3d->player.dir)
		map_content_err(cub3d, "invalid map: missing player");
}

void	file_verify(char *s)
{
	char	*e;

	e = ft_strrchr(s, '/');
	if ((e && !*(e + 1)) || !*s)
		exit_err(0, "no file found", 0);
	if ((e && *(e + 1) == '.') || (!e && *s == '.'))
		exit_err(0, "file should not be hidden file", 0);
	e = ft_strnstr(s, ".cub", ft_strlen(s));
	if (!e || *(e + 4) != 0)
		exit_err(0, "file extension should be \".cub\"", 0);
}

void	clear_map(t_cub3d *cub3d)
{
	t_map	*map;

	map = cub3d->map;
	if (!map)
		return ;
	if (cub3d->mlx)
	{
		if (map->img_no.img)
			mlx_destroy_image(cub3d->mlx, map->img_no.img);
		if (map->img_so.img)
			mlx_destroy_image(cub3d->mlx, map->img_so.img);
		if (map->img_we.img)
			mlx_destroy_image(cub3d->mlx, map->img_we.img);
		if (map->img_ea.img)
			mlx_destroy_image(cub3d->mlx, map->img_ea.img);
	}
	if (map->tmp)
		free(map->tmp);
	clear_sl(map->content);
	free(map);
}
