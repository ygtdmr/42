/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 08:18:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/24 08:26:17 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_side_dist(t_cam *cam, t_dda *dda, t_player *player)
{
	if (cam->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (player->x - dda->map_x) * dda->delta_dist_x;
	}
	else
	{
		dda->step_x = 1;
		dda->side_dist_x = (dda->map_x + 1.0 - player->x) * dda->delta_dist_x;
	}
	if (cam->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (player->y - dda->map_y) * dda->delta_dist_y;
	}
	else
	{
		dda->step_y = 1;
		dda->side_dist_y = (dda->map_y + 1.0 - player->y) * dda->delta_dist_y;
	}
}

static void	loop_ray(t_cub3d *cub3d, t_cam *cam, t_dda *dda)
{
	while (cub3d->map->content[dda->map_y][dda->map_x] != '1')
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
	}
	if (cam->dda.side)
		dda->wall_x = cub3d->player.x + cam->perp_wall_dist * cam->ray_dir_x;
	else
		dda->wall_x = cub3d->player.y + cam->perp_wall_dist * cam->ray_dir_y;
	dda->wall_x -= floor(dda->wall_x);
}

static void	render_map(t_cub3d *cub3d, t_cam *cam, t_dda *dda)
{
	int		x;
	double	camera_x;

	x = 0;
	while (x < cub3d->width)
	{
		camera_x = 2 * x / (double)cub3d->width - 1;
		cam->ray_dir_x = cam->dir_x + cam->plane_x * camera_x;
		cam->ray_dir_y = cam->dir_y + cam->plane_y * camera_x;
		dda->delta_dist_x = fabs(1 / cam->ray_dir_x);
		dda->delta_dist_y = fabs(1 / cam->ray_dir_y);
		dda->map_x = (int)cub3d->player.x;
		dda->map_y = (int)cub3d->player.y;
		get_side_dist(cam, dda, &cub3d->player);
		loop_ray(cub3d, cam, dda);
		if (dda->side)
			cam->perp_wall_dist = \
(dda->map_y - cub3d->player.y + (1 - dda->step_y) / 2) / cam->ray_dir_y;
		else
			cam->perp_wall_dist = \
(dda->map_x - cub3d->player.x + (1 - dda->step_x) / 2) / cam->ray_dir_x;
		cam->line_height = (int)(cub3d->height / cam->perp_wall_dist);
		draw_map(cub3d, cam, x++);
	}
}

int	render(t_cub3d *cub3d)
{
	handle_action(cub3d);
	draw_floor_ceiling(cub3d);
	render_map(cub3d, &cub3d->player.cam, &cub3d->player.cam.dda);
	mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->container.img, 0, 0);
	return (0);
}
