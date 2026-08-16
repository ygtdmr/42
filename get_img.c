/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:50:45 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/18 12:55:24 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*get_img(t_sldata *sld, char *path, char c)
{
	void	*img;
	int		w;
	int		h;

	w = 64;
	h = 64;
	if (!path)
		path = get_default_path(c);
	if (open(path, O_RDONLY) == -1)
		exit_sl(sld, "Error: texture path not found.\n", 1);
	img = mlx_xpm_file_to_image(sld->mlx, path, &w, &h);
	if (!img)
		exit_sl(sld, "Error: xpm file not valid.\n", 1);
	return (img);
}
