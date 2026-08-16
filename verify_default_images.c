/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_default_images.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:21:09 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/18 13:44:28 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	verify_default_images(t_sldata *sld)
{
	void	*img;

	img = get_img(sld, 0, '1');
	if (img)
		mlx_destroy_image(sld->mlx, img);
	img = get_img(sld, 0, '0');
	if (img)
		mlx_destroy_image(sld->mlx, img);
	img = get_img(sld, 0, 'C');
	if (img)
		mlx_destroy_image(sld->mlx, img);
	img = get_img(sld, 0, 'E');
	if (img)
		mlx_destroy_image(sld->mlx, img);
	img = get_img(sld, 0, 'P');
	if (img)
		mlx_destroy_image(sld->mlx, img);
}
