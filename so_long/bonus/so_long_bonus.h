/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:02:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/15 15:45:07 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define KEY_ESC	65307

# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100

# define KEY_UP		65362
# define KEY_RIGHT	65363
# define KEY_DOWN	65364
# define KEY_LEFT	65361

# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include "../lib/libft/libft.h"
# include "../lib/get_next_line/get_next_line.h"
# include "../lib/minilibx-linux/mlx.h"

typedef struct s_slva
{
	int	cc;
	int	ise;
	int	isp;
}	t_slva;

typedef struct s_slp
{
	int	x;
	int	y;
}	t_slp;

typedef struct s_sldata
{
	char	**map;
	void	*mlx;
	void	*win;
	int		mw;
	int		mh;
	int		col;
	int		mvc;
	t_slp	pp;
	t_slp	pe;
	t_list	*el;
}	t_sldata;

typedef struct s_enemy
{
	int		side;
	t_slp	p;
}	t_enemy;

int		str_clen(char *s, char c);
int		isvc(char *line);
int		map_verifiy(t_sldata *sld, int mfd);
void	map_render(t_sldata *sld);
void	redraw_img(t_sldata *sld, void *img, int x, int y);
void	*get_img(t_sldata *sld, char *path, char c);
char	**get_map(t_sldata *sld, int mfd);
int		handle_keyhook(int code, t_sldata *sld);
int		exit_sl(t_sldata *sld, char *msg);
t_slp	init_p(int x, int y);
int		map_verify_path(t_sldata *sld, char **map);

void	do_anim_player(t_sldata *sld, int code);
void	do_anim_enemy(t_sldata *sld, t_enemy *enemy);
int		enemy_handle(t_sldata *sld);
t_list	*enemy_init(t_sldata *sld);

#endif
