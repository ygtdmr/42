/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:02:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/28 16:56:53 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>

# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_RIGHT	65363
# define KEY_LEFT	65361
# define IMG_SIZE	64
# define MAP_SIZE	12
# define MOV_SPEED	0.025
# define ROT_SPEED	0.025
# define COL_MARGIN	0.2

typedef struct s_tex
{
	double	step;
	double	pos;
	int		x;
	int		y;
}	t_tex;

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_x;
}	t_dda;

typedef struct s_cam
{
	double	dir_x;
	double	dir_y;
	double	ray_dir_x;
	double	ray_dir_y;
	double	plane_x;
	double	plane_y;
	double	perp_wall_dist;
	int		line_height;
	t_dda	dda;
}	t_cam;

typedef struct s_player
{
	t_cam	cam;
	char	dir;
	double	x;
	double	y;
	int		press_w;
	int		press_a;
	int		press_s;
	int		press_d;
	int		press_right;
	int		press_left;
}	t_player;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		rgb_f;
	int		rgb_c;
	char	**content;
	void	*tmp;
	t_img	img_no;
	t_img	img_so;
	t_img	img_we;
	t_img	img_ea;
}	t_map;

typedef struct s_cub3d
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	t_map		*map;
	t_player	player;
	t_img		container;
}	t_cub3d;

void	exit_err(t_cub3d *cub3d, char *msg1, char *msg2);
int		close_window(t_cub3d *cub3d);
int		render(t_cub3d *cub3d);

int		str_ms(char **dest, char *src);
int		str_setonly(char *dest, char *set);
int		str_cs(char **dest, char *set);

void	clear_sl(char **sl);
void	add_sl(char ***sl, char *val);
char	**dup_sl(char **sl);

void	clear_map(t_cub3d *cub3d);
void	parse_map(t_cub3d *cub3d, char *path);

void	file_verify(char *s);
void	scan_map_content(t_cub3d *cub3d, char **dup);

void	handle_action(t_cub3d *cub3d);
int		handle_key_press(int code, t_cub3d *cub3d);
int		handle_key_release(int code, t_cub3d *cub3d);

void	init_cam(t_player *player);
void	init_container(t_cub3d *cub3d);
void	put_pixel(t_cub3d *cub3d, int x, int y, int color);

void	cam_action_move(t_cam *cam, t_cub3d *cub3d, int x, int y);
void	cam_action_rotate(t_cam *cam, int side);

void	draw_floor_ceiling(t_cub3d *cub3d);
void	draw_map(t_cub3d *cub3d, t_cam *cam, int x);

#endif
