/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:11:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/06 17:42:48 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	*get_img(t_sldata *sld, char c)
{
	int		w;
	int		h;
	char	*path;

	w = 64;
	h = 64;
	path = 0;
	if (c == '1')
		path = "images/wall.xpm";
	else if(c == '0')
		path = "images/fs.xpm";
	else if(c == 'C')
		path = "images/col.xpm";
	else if(c == 'E')
		path = "images/exit_off.xpm";
	else if(c == 'P')
		path = "images/player.xpm";
	return (mlx_xpm_file_to_image(sld->mlx, path, &w, &h));
}

void	redraw_img(t_sldata *sld, char c, int x, int y)
{
	void	*img;

	img = get_img(sld, c);
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
			img = get_img(sld, sld->map[ih][iw]);
			mlx_put_image_to_window(sld->mlx, sld->win, img, iw * 64, ih * 64);
			mlx_destroy_image(sld->mlx, img);
			iw++;
		}
		ih++;
	}
}
