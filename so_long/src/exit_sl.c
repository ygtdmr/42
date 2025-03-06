/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_sl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:21:09 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/06 16:31:32 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int exit_sl(t_sldata *sld)
{
	while (sld->mh)
		free(sld->map[--sld->mh]);
	free(sld->map);
	mlx_destroy_window(sld->mlx, sld->win);
	mlx_loop_end(sld->mlx);
	return (0);
}
