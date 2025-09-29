/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:11:31 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/24 06:12:43 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cam_action_move(t_cam *cam, t_cub3d *cub3d, int x, int y)
{
	double	new_x;
	double	new_y;

	if (y != 0)
	{
		new_x = y * (cam->dir_x * MOV_SPEED);
		new_y = y * (cam->dir_y * MOV_SPEED);
		if ('1' != cub3d->map->content\
[(int)cub3d->player.y][(int)(cub3d->player.x + new_x * (1 + COL_MARGIN))])
			cub3d->player.x += new_x;
		if ('1' != cub3d->map->content\
[(int)(cub3d->player.y + new_y * (1 + COL_MARGIN))][(int)cub3d->player.x])
			cub3d->player.y += new_y;
	}
	if (x != 0)
	{
		new_x = x * (cam->plane_x * MOV_SPEED);
		new_y = x * (cam->plane_y * MOV_SPEED);
		if ('1' != cub3d->map->content\
[(int)cub3d->player.y][(int)(cub3d->player.x + new_x)])
			cub3d->player.x += new_x;
		if ('1' != cub3d->map->content\
[(int)(cub3d->player.y + new_y)][(int)cub3d->player.x])
			cub3d->player.y += new_y;
	}
}

void	cam_action_rotate(t_cam *cam, int side)
{
	double	old_dir_x;
	double	old_plane_x;
	double	speed;

	old_dir_x = cam->dir_x;
	old_plane_x = cam->plane_x;
	speed = side * ROT_SPEED;
	cam->dir_x = cam->dir_x * cos(speed) - cam->dir_y * sin(speed);
	cam->dir_y = old_dir_x * sin(speed) + cam->dir_y * cos(speed);
	cam->plane_x = cam->plane_x * cos(speed) - cam->plane_y * sin(speed);
	cam->plane_y = old_plane_x * sin(speed) + cam->plane_y * cos(speed);
}

void	init_cam(t_player *player)
{
	ft_bzero(&player->cam, sizeof(t_cam));
	if (player->dir == 'N')
	{
		player->cam.dir_y = -1;
		player->cam.plane_x = 0.66;
	}
	else if (player->dir == 'S')
	{
		player->cam.dir_y = 1;
		player->cam.plane_x = -0.66;
	}
	else if (player->dir == 'E')
	{
		player->cam.dir_x = 1;
		player->cam.plane_y = 0.66;
	}
	else if (player->dir == 'W')
	{
		player->cam.dir_x = -1;
		player->cam.plane_y = -0.66;
	}
}
