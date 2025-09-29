/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:48:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/24 06:06:54 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_action(t_cub3d *cub3d)
{
	if (cub3d->player.press_w)
		cam_action_move(&cub3d->player.cam, cub3d, 0, 1);
	if (cub3d->player.press_s)
		cam_action_move(&cub3d->player.cam, cub3d, 0, -1);
	if (cub3d->player.press_d)
		cam_action_move(&cub3d->player.cam, cub3d, 1, 0);
	if (cub3d->player.press_a)
		cam_action_move(&cub3d->player.cam, cub3d, -1, 0);
	if (cub3d->player.press_right)
		cam_action_rotate(&cub3d->player.cam, 1);
	else if (cub3d->player.press_left)
		cam_action_rotate(&cub3d->player.cam, -1);
}

int	handle_key_press(int code, t_cub3d *cub3d)
{
	if (code == KEY_W)
		cub3d->player.press_w = 1;
	else if (code == KEY_A)
		cub3d->player.press_a = 1;
	else if (code == KEY_S)
		cub3d->player.press_s = 1;
	else if (code == KEY_D)
		cub3d->player.press_d = 1;
	else if (code == KEY_LEFT)
		cub3d->player.press_left = 1;
	else if (code == KEY_RIGHT)
		cub3d->player.press_right = 1;
	return (0);
}

int	handle_key_release(int code, t_cub3d *cub3d)
{
	if (code == KEY_ESC)
		close_window(cub3d);
	else if (code == KEY_W)
		cub3d->player.press_w = 0;
	else if (code == KEY_A)
		cub3d->player.press_a = 0;
	else if (code == KEY_S)
		cub3d->player.press_s = 0;
	else if (code == KEY_D)
		cub3d->player.press_d = 0;
	else if (code == KEY_LEFT)
		cub3d->player.press_left = 0;
	else if (code == KEY_RIGHT)
		cub3d->player.press_right = 0;
	return (0);
}
