/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 07:57:18 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/27 15:10:06 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	void	*dest;

	dest = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

t_img	new_img(void *mlx, char *path, int w, int h)
{
	t_img	img;

	if (path)
		img.mlx_img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	else
		img.mlx_img = mlx_new_image(mlx, w, h);
	if (img.mlx_img)
		img.addr = \
mlx_get_data_addr(img.mlx_img, &img.bpp, &img.line_length, &img.endian);
	return (img);
}
