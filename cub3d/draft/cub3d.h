/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:02:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/27 16:41:50 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line/get_next_line.h"
# include ".minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <string.h>
# include <errno.h>
# include <math.h>

# include <stdio.h>

# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100
# define KEY_LEFT		65361
# define KEY_RIGHT		65363
# define KEY_ESC		65307

# define PRESS_W		0
# define PRESS_A		1
# define PRESS_S		2
# define PRESS_D		3
# define PRESS_LEFT		4
# define PRESS_RIGHT	5

# define CAM_FOV		0.66

# define IMG_SIZE		64
# define MAP_SIZE		12

# define MOV_SPEED		0.005
# define ROT_SPEED		0.005

# define COL_MARGIN		0.2

typedef struct s_cam
{
	double	x;
	double	y;
	double	plane_x;
	double	plane_y;
	double	ray_x;
	double	ray_y;
	int		controls;
	char	dir;
}	t_cam;

typedef struct s_img
{
	void	*mlx_img;
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
	int			width;
	int			height;
	void		*mlx;
	void		*win;
	t_map		map;
	t_cam		cam;
	t_img		container;
}	t_cub3d;

void	exit_err(t_cub3d *cub3d, char *msg1, char *msg2);
int		close_window(t_cub3d *cub3d);

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

t_img	new_img(void *mlx, char *path, int w, int h);
void	put_pixel(t_img *img, int x, int y, int color);

void	handle_action(t_cub3d *cub3d);
int		handle_key_press(int code, t_cub3d *cub3d);
int		handle_key_release(int code, t_cub3d *cub3d);


t_cam	init_cam(int x, int y, char dir);

int		render(t_cub3d *cub3d);

#endif
