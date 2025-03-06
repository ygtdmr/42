/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:02:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/04 18:55:19 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>

#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include "../lib/libft/libft.h"
#include "../lib/get_next_line/get_next_line.h"

typedef struct s_sldata
{
	char	**map;
	void	*mlx;
	void	*win;
	char	*player;
	int 	mw;
	int 	mh;
	int		col;
	int		exit;
}	t_sldata;

int		map_verifiy(t_sldata *sld, int mfd);
void	map_render(t_sldata *sld);
char	**get_map(t_sldata *sld, char *mpath);
int		handle_keyhook(int code, void *pm);

#endif