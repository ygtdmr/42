/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 06:46:16 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/24 08:31:20 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_floor_ceiling(t_cub3d *cub3d)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < cub3d->height / 2)
	{
		x = 0;
		while (x < cub3d->width)
			put_pixel(cub3d, x++, y, cub3d->map->rgb_c);
		y++;
	}
	while (y < cub3d->height)
	{
		x = 0;
		while (x < cub3d->width)
			put_pixel(cub3d, x++, y, cub3d->map->rgb_f);
		y++;
	}
}

static t_img	*get_texture(t_cub3d *cub3d, t_cam *cam)
{
	if (cam->dda.side == 0)
	{
		if (cam->ray_dir_x > 0)
			return (&cub3d->map->img_ea);
		else
			return (&cub3d->map->img_we);
	}
	else
	{
		if (cam->ray_dir_y > 0)
			return (&cub3d->map->img_so);
		else
			return (&cub3d->map->img_no);
	}
}

static int	get_tex_color(t_img *tex, int tex_x, int tex_y)
{
	char	*addr;

	addr = tex->addr
		+ tex_y * tex->line_length
		+ tex_x * (tex->bpp / 8);
	return (*(unsigned int *)addr);
}

void	draw_map(t_cub3d *cub3d, t_cam *cam, int x)
{
	int		draw_start;
	int		draw_end;
	t_tex	tex;

	draw_start = -cam->line_height / 2 + cub3d->height / 2;
	draw_end = cam->line_height / 2 + cub3d->height / 2;
	if (draw_start < 0)
		draw_start = 0;
	if (draw_end >= cub3d->height)
		draw_end = cub3d->height - 1;
	tex.x = (int)(cam->dda.wall_x * IMG_SIZE);
	if ((!cam->dda.side && cam->ray_dir_x > 0) || \
(cam->dda.side && cam->ray_dir_y < 0))
		tex.x = IMG_SIZE - tex.x - 1;
	tex.step = (double)IMG_SIZE / cam->line_height;
	tex.pos = \
(draw_start - cub3d->height / 2 + cam->line_height / 2) * tex.step;
	while (draw_start < draw_end)
	{
		tex.y = (int)tex.pos & (IMG_SIZE - 1);
		tex.pos += tex.step;
		put_pixel(cub3d, x, draw_start++, \
get_tex_color(get_texture(cub3d, cam), tex.x, tex.y));
	}
}
