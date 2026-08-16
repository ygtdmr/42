/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 09:52:32 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/19 13:52:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_verify_path(t_sldata *sld, char **map)
{
	t_slverify_path	va;
	int				imh;

	ft_memset(&va, 0, sizeof(va));
	scan_map(&va, map, sld->pp.x, sld->pp.y);
	imh = 0;
	while (imh < sld->mh)
		free(map[imh++]);
	free(map);
	if (!(va.cc == sld->col && va.ise && va.isp))
		exit_sl(sld, "Error: game is not playable to this map.\n", 1);
}
