/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:02:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/16 17:30:40 by yidemir          ###   ########.fr       */
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

# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"

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
}	t_sldata;

int		str_clen(char *s, char c);
int		isvc(char *line);
int		map_verifiy(t_sldata *sld, int mfd);
void	map_render(t_sldata *sld);
void	redraw_img(t_sldata *sld, void *img, int x, int y);
void	*get_img(t_sldata *sld, char *path, char c);
char	**get_map(t_sldata *sld, int mfd);
int		handle_keyhook(int code, t_sldata *sld);
void	exit_sl(t_sldata *sld, char *msg, int code);
t_slp	init_p(int x, int y);
int		map_verify_path(t_sldata *sld, char **map);

#endif
