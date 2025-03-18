/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_sl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:21:09 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/18 14:20:47 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_sl(t_sldata *sld, char *msg, int code)
{
	if (sld)
	{
		if (sld->map)
		{
			while (sld->mh)
				free(sld->map[--sld->mh]);
			free(sld->map);
		}
		if (sld->win)
			mlx_destroy_window(sld->mlx, sld->win);
		if (sld->mlx)
		{
			mlx_destroy_display(sld->mlx);
			free(sld->mlx);
		}
	}
	if (msg)
		write(1 + (code == 1), msg, ft_strlen(msg));
	exit(code);
}
