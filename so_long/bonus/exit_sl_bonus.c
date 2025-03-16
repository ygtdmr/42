/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_sl_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:21:09 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/16 17:40:45 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	exit_sl(t_sldata *sld, char *msg, int code)
{
	if (sld)
	{
		while (sld->mh)
			free(sld->map[--sld->mh]);
		free(sld->map);
		ft_lstclear(&sld->el, free);
		mlx_destroy_window(sld->mlx, sld->win);
		mlx_destroy_display(sld->mlx);
		free(sld->mlx);
	}
	if (msg)
		write(1, msg, ft_strlen(msg));
	exit(code);
}
