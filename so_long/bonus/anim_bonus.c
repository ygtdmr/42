/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:05:59 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/16 17:11:29 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	do_anim_player(t_sldata *sld, int code)
{
	static int	f;
	static int	oldcode;
	char		path[34];

	if (f < 7 && oldcode == code)
		f++;
	else
		f = 0;
	oldcode = code;
	if (code == KEY_W || code == KEY_UP)
		ft_strlcpy(path, "bonus/textures/player_run_t_X.xpm", 34);
	else if (code == KEY_S || code == KEY_DOWN)
		ft_strlcpy(path, "bonus/textures/player_run_b_X.xpm", 34);
	else if (code == KEY_A || code == KEY_LEFT)
		ft_strlcpy(path, "bonus/textures/player_run_l_X.xpm", 34);
	else if (code == KEY_D || code == KEY_RIGHT)
		ft_strlcpy(path, "bonus/textures/player_run_r_X.xpm", 34);
	*ft_strchr(path, 'X') = f + '0';
	redraw_img(sld, get_img(sld, path, 0), sld->pp.x, sld->pp.y);
}

void	do_anim_enemy(t_sldata *sld, t_enemy *enemy)
{
	static int	f;
	static int	oldcode;
	char		path[33];

	if (f < 7 && oldcode == enemy->side)
		f++;
	else
		f = 0;
	oldcode = enemy->side;
	if (enemy->side == 0)
		ft_strlcpy(path, "bonus/textures/enemy_run_l_X.xpm", 33);
	else if (enemy->side == 1)
		ft_strlcpy(path, "bonus/textures/enemy_run_r_X.xpm", 33);
	*ft_strchr(path, 'X') = f + '0';
	redraw_img(sld, get_img(sld, path, 0), enemy->p.x, enemy->p.y);
}
