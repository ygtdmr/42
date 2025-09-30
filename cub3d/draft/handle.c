/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:48:30 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/27 15:52:45 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_action(t_cub3d *cub3d)
{
	if (cub3d->cam.controls & (1 << PRESS_W))
		printf("player moving: w\n");
	if (cub3d->cam.controls & (1 << PRESS_A))
		printf("player moving: a\n");
	if (cub3d->cam.controls & (1 << PRESS_S))
		printf("player moving: s\n");
	if (cub3d->cam.controls & (1 << PRESS_D))
		printf("player moving: d\n");
	if (cub3d->cam.controls & (1 << PRESS_RIGHT))
		printf("player moving: right\n");
	else if (cub3d->cam.controls & (1 << PRESS_LEFT))
		printf("player moving: left\n");
}

int	handle_key_press(int code, t_cub3d *cub3d)
{
	if (code == KEY_W)
		cub3d->cam.controls |= (1 << PRESS_W);
	else if (code == KEY_A)
		cub3d->cam.controls |= (1 << PRESS_A);
	else if (code == KEY_S)
		cub3d->cam.controls |= (1 << PRESS_S);
	else if (code == KEY_D)
		cub3d->cam.controls |= (1 << PRESS_D);
	else if (code == KEY_LEFT)
		cub3d->cam.controls |= (1 << PRESS_LEFT);
	else if (code == KEY_RIGHT)
		cub3d->cam.controls |= (1 << PRESS_RIGHT);
	return (0);
}

int	handle_key_release(int code, t_cub3d *cub3d)
{
	if (code == KEY_ESC)
		close_window(cub3d);
	else if (code == KEY_W)
		cub3d->cam.controls &= ~(1 << PRESS_W);
	else if (code == KEY_A)
		cub3d->cam.controls &= ~(1 << PRESS_A);
	else if (code == KEY_S)
		cub3d->cam.controls &= ~(1 << PRESS_S);
	else if (code == KEY_D)
		cub3d->cam.controls &= ~(1 << PRESS_D);
	else if (code == KEY_LEFT)
		cub3d->cam.controls &= ~(1 << PRESS_LEFT);
	else if (code == KEY_RIGHT)
		cub3d->cam.controls &= ~(1 << PRESS_RIGHT);
	return (0);
}
