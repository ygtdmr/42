/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 15:15:14 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/28 08:30:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_cam	init_cam(int x, int y, char dir)
{
	t_cam	cam;

	ft_bzero(&cam, sizeof(t_cam));
	cam.x = x;
	cam.y = y;
	cam.dir = dir;
	return (cam);
}

int	render(t_cub3d *cub3d)
{
	double	scan_plane;

	handle_action(cub3d);
	scan_plane = (cub3d->cam.x - cub3d->cam.plane_x);
	while (scan_plane <= (cub3d->cam.x + CAM_FOV))
	{
		while (cub3d->map.content[(int)cub3d->cam.ray_y][(int)cub3d->cam.ray_x] != '1')
		{
			cub3d->cam.ray_y += 0.1;
		}
		scan_plane += 0.1;
	}
	return (0);
}
