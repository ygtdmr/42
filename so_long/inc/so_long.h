/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:02:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/06 18:58:49 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define KEY_ESC	65307

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364
# define KEY_LEFT	65361

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"

typedef struct s_slc
{
	int	x;
	int	y;
}	t_slc;

typedef struct s_sldata
{
	char	**map;
	void	*mlx;
	void	*win;
	int		mw;
	int		mh;
	int		col;
	int		exit;
	int		mvc;
	t_slc	pc;
}	t_sldata;

int		map_verifiy(t_sldata *sld, int mfd);
void	map_render(t_sldata *sld);
void	redraw_img(t_sldata *sld, char c, int x, int y);
char	**get_map(t_sldata *sld, int mfd);
int		handle_keyhook(int code, t_sldata *sld);
int		exit_sl(t_sldata *sld);
t_slc	init_pc(int x, int y);

#endif
