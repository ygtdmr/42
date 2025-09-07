/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 10:59:04 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/07 18:19:53 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clear_map(t_cub3d *cub3d)
{
	t_map	*map;

	map = cub3d->map;
	if (!map)
		return ;
	if (cub3d->mlx)
	{
		if (map->img_no)
			mlx_destroy_image(cub3d->mlx, map->img_no);
		if (map->img_so)
			mlx_destroy_image(cub3d->mlx, map->img_so);
		if (map->img_we)
			mlx_destroy_image(cub3d->mlx, map->img_we);
		if (map->img_ea)
			mlx_destroy_image(cub3d->mlx, map->img_ea);
	}
	if (map->tmp)
		free(map->tmp);
	clear_sl(map->content);
	free(map);
}
