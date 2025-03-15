/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:50:45 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/15 16:27:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*get_img(t_sldata *sld, char *path, char c)
{
	int		w;
	int		h;

	w = 64;
	h = 64;
	if (!path)
	{
		if (c == '1')
			path = "images/wall.xpm";
		else if (c == '0')
			path = "images/fs.xpm";
		else if (c == 'C')
			path = "images/col.xpm";
		else if (c == 'E')
			path = "images/exit_0.xpm";
		else if (c == 'P')
			path = "images/player.xpm";
		else if (c == 'N')
			path = "images/anim/enemy_run_r_0.xpm";
	}
	return (mlx_xpm_file_to_image(sld->mlx, path, &w, &h));
}
