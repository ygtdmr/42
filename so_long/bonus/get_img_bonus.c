/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:50:45 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/16 17:34:04 by yidemir          ###   ########.fr       */
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
			path = "textures/wall.xpm";
		else if (c == '0')
			path = "textures/fs.xpm";
		else if (c == 'C')
			path = "textures/col.xpm";
		else if (c == 'E')
			path = "textures/exit_0.xpm";
		else if (c == 'P')
			path = "textures/player.xpm";
		else if (c == 'N')
			path = "bonus/textures/enemy_run_r_0.xpm";
	}
	if (open(path, O_RDONLY) == -1)
		exit_sl(sld, "Error: texture path not found.\n", 1);
	return (mlx_xpm_file_to_image(sld->mlx, path, &w, &h));
}
