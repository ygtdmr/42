/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 15:15:54 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/15 15:45:58 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	enemy_control(t_sldata *sld, t_enemy *enemy)
{
	t_slp	ep;

	ep = enemy->p;
	redraw_img(sld, get_img(sld, 0, '0'), ep.x, ep.y);
	sld->map[ep.y][ep.x] = '0';
	if (enemy->side && (sld->map[ep.y][ep.x + 1] == '0'))
		enemy->p.x++;
	else if (!enemy->side && (sld->map[ep.y][ep.x - 1] == '0'))
		enemy->p.x--;
	else if (enemy->side && (sld->map[ep.y][ep.x + 1] == 'P'))
		return (exit_sl(sld, "Game over!\n"));
	else if (!enemy->side && (sld->map[ep.y][ep.x - 1] == 'P'))
		return (exit_sl(sld, "Game over!\n"));
	else
		enemy->side = !enemy->side;
	do_anim_enemy(sld, enemy);
	sld->map[enemy->p.y][enemy->p.x] = 'N';
	return (1);
}

t_list	*enemy_init(t_sldata *sld)
{
	t_enemy	*ne;
	t_list	*el;
	int		i;
	int		il;

	el = 0;
	i = 0;
	while (i < sld->mh)
	{
		il = 0;
		while (sld->map[i][il] && sld->map[i][il] != '\n')
		{
			if (sld->map[i][il++] == 'N')
			{
				ne = malloc(sizeof(t_enemy));
				if (!ne)
					return (0);
				ne->p = init_p(il - 1, i);
				ne->side = 0;
				ft_lstadd_back(&el, ft_lstnew(ne));
			}
		}
		i++;
	}
	return (el);
}

int	enemy_handle(t_sldata *sld)
{
	static time_t	st;
	t_list			*tel;

	tel = sld->el;
	if (!sld->el)
		return (0);
	if ((time(0) - st) >= 1)
	{
		while (tel)
		{
			if (!enemy_control(sld, (t_enemy *) tel->content))
				return (0);
			tel = tel->next;
		}
		time(&st);
	}
	return (0);
}
