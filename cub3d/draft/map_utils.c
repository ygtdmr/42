/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:59:04 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/27 16:16:19 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	map_content_err(t_cub3d *cub3d, char *str)
{
	clear_sl(cub3d->map.tmp);
	cub3d->map.tmp = 0;
	exit_err(cub3d, str, 0);
}

static void	scan_content_fill(t_cub3d *cub3d, char **dup, size_t x, size_t y)
{
	if (!(x && y) || !dup[y][x] || !dup[y + 1] || dup[y][x] == ' ')
		map_content_err(cub3d, "invalid map: map must surround with wall");
	else if (dup[y][x] == 'N' || dup[y][x] == 'S' || \
dup[y][x] == 'E' || dup[y][x] == 'W')
	{
		if (cub3d->cam.dir)
			map_content_err(cub3d, "invalid map: detected too many players");
		else
			cub3d->cam = init_cam(x, y, dup[y][x]);
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
	if (!cub3d->cam.dir)
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
	if (cub3d->mlx)
	{
		if (cub3d->map.img_no.mlx_img)
			mlx_destroy_image(cub3d->mlx, cub3d->map.img_no.mlx_img);
		if (cub3d->map.img_so.mlx_img)
			mlx_destroy_image(cub3d->mlx, cub3d->map.img_so.mlx_img);
		if (cub3d->map.img_we.mlx_img)
			mlx_destroy_image(cub3d->mlx, cub3d->map.img_we.mlx_img);
		if (cub3d->map.img_ea.mlx_img)
			mlx_destroy_image(cub3d->mlx, cub3d->map.img_ea.mlx_img);
	}
	if (cub3d->map.tmp)
		free(cub3d->map.tmp);
	clear_sl(cub3d->map.content);
}
