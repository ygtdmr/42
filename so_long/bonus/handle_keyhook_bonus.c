/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyhook_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 18:45:32 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/16 17:32:46 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	handle_action(t_sldata *sld, int x, int y)
{
	void	*img_exit_1;

	if (sld->map[y][x] == 'E')
	{
		if (sld->col == 0)
			exit_sl(sld, "Good job!\n", 0);
		return (0);
	}
	if (sld->map[y][x] == 'C')
	{
		sld->col--;
		if (!sld->col)
		{
			img_exit_1 = get_img(sld, "textures/exit_1.xpm", 0);
			redraw_img(sld, img_exit_1, sld->pe.x, sld->pe.y);
		}
	}
	return (1);
}

static int	do_action(t_sldata *sld, int x, int y)
{
	if (sld->map[y][x] == '1' || !handle_action(sld, x, y))
		return (0);
	if (sld->map[y][x] == 'N')
		exit_sl(sld, "Game over!\n", 0);
	redraw_img(sld, get_img(sld, 0, '0'), sld->pp.x, sld->pp.y);
	sld->map[sld->pp.y][sld->pp.x] = '0';
	sld->map[y][x] = 'P';
	sld->pp.x = x;
	sld->pp.y = y;
	return (1);
}

static void	view_count(t_sldata *sld)
{
	char	*s;
	char	*smvc;

	smvc = ft_itoa(sld->mvc);
	s = ft_strjoin("Move count: ", smvc);
	redraw_img(sld, get_img(sld, 0, '1'), 0, 0);
	redraw_img(sld, get_img(sld, 0, '1'), 1, 0);
	mlx_string_put(sld->mlx, sld->win, 8, 16, 0xffffff, s);
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
	free(s);
	free(smvc);
}

int	handle_keyhook(int code, t_sldata *sld)
{
	int	status;

	status = 0;
	if (code == KEY_ESC)
		exit_sl(sld, 0, 0);
	else if (code == KEY_W || code == KEY_UP)
		status = do_action(sld, sld->pp.x, sld->pp.y - 1);
	else if (code == KEY_S || code == KEY_DOWN)
		status = do_action(sld, sld->pp.x, sld->pp.y + 1);
	else if (code == KEY_A || code == KEY_LEFT)
		status = do_action(sld, sld->pp.x - 1, sld->pp.y);
	else if (code == KEY_D || code == KEY_RIGHT)
		status = do_action(sld, sld->pp.x + 1, sld->pp.y);
	if (status)
	{
		do_anim_player(sld, code);
		sld->mvc++;
		view_count(sld);
	}
	return (0);
}
