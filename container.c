/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   container.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 07:57:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/24 07:31:39 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_cub3d *cub3d, int x, int y, int color)
{
	t_img	*c;
	void	*dest;

	c = &cub3d->container;
	dest = c->addr + (y * c->line_length + x * (c->bpp / 8));
	*(unsigned int *)dest = color;
}

void	init_container(t_cub3d *cub3d)
{
	t_img	*c;

	c = &cub3d->container;
	c->img = mlx_new_image(cub3d->mlx, cub3d->width, cub3d->height);
	c->addr = mlx_get_data_addr(c->img, &c->bpp, &c->line_length, &c->endian);
}
