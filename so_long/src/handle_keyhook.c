/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyhook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:45:32 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/06 18:59:44 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	handle_action(t_sldata *sld, int x, int y)
{
	if (sld->map[y][x] == 'E')
	{
		if (sld->col == 0)
			exit_sl(sld);
		return (0);
	}
	if (sld->map[y][x] == 'C')
		sld->col--;
	return (1);
}

static void	do_action(t_sldata *sld, int x, int y)
{
	if (sld->map[y][x] == '1' || !handle_action(sld, x, y))
		return ;
	redraw_img(sld, '0', sld->pc.x, sld->pc.y);
	sld->map[y][x] = '0';
	redraw_img(sld, 'P', x, y);
	sld->map[y][x] = 'P';
	sld->pc.x = x;
	sld->pc.y = y;
	sld->mvc++;
	printf("Move count: %i\n", sld->mvc);
}

int	handle_keyhook(int code, t_sldata *sld)
{
	if (code == KEY_ESC)
		exit_sl(sld);
	else if (code == KEY_W || code == KEY_UP)
		do_action(sld, sld->pc.x, sld->pc.y - 1);
	else if (code == KEY_S || code == KEY_DOWN)
		do_action(sld, sld->pc.x, sld->pc.y + 1);
	else if (code == KEY_A || code == KEY_LEFT)
		do_action(sld, sld->pc.x - 1, sld->pc.y);
	else if (code == KEY_D || code == KEY_RIGHT)
		do_action(sld, sld->pc.x + 1, sld->pc.y);
	return (0);
}
