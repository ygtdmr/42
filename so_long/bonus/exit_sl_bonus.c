/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_sl_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:21:09 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/15 15:09:31 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exit_sl(t_sldata *sld, char *msg)
{
	while (sld->mh)
		free(sld->map[--sld->mh]);
	free(sld->map);
	ft_lstclear(&sld->el, free);
	mlx_loop_end(sld->mlx);
	if (msg)
		write(1, msg, ft_strlen(msg));
	return (0);
}
