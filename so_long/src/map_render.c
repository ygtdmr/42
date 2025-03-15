/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:11:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/15 14:51:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	redraw_img(t_sldata *sld, void *img, int x, int y)
{
	mlx_put_image_to_window(sld->mlx, sld->win, img, x * 64, y * 64);
	mlx_destroy_image(sld->mlx, img);
}

void	map_render(t_sldata *sld)
{
	void	*img;
	int		iw;
	int		ih;

	ih = 0;
	while (ih < sld->mh)
	{
		iw = 0;
		while (sld->map[ih][iw] && sld->map[ih][iw] != '\n')
		{
			img = get_img(sld, 0, sld->map[ih][iw]);
			mlx_put_image_to_window(sld->mlx, sld->win, img, iw * 64, ih * 64);
			mlx_destroy_image(sld->mlx, img);
			iw++;
		}
		ih++;
	}
}
