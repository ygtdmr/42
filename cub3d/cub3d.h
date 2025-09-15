/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:02:19 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/14 16:05:14 by yidemir          ###   ########.fr       */
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

# include <stdio.h>

# define KEY_ESC	65307
# define KEY_W		119
# define KEY_A		97
# define KEY_S		115
# define KEY_D		100
# define KEY_RIGHT	65363
# define KEY_LEFT	65361
# define IMG_SIZE	64

typedef struct s_map
{
	int		rgb_f;
	int		rgb_c;
	char	**content;
	char	*tmp;
	void	*img_no;
	void	*img_so;
	void	*img_we;
	void	*img_ea;
}	t_map;

typedef struct s_cub3d
{
	void	*mlx;
	void	*win;
	t_map	*map;
}	t_cub3d;

void	clear_map(t_cub3d *cub3d);
void	exit_err(t_cub3d *cub3d, char *msg1, char *msg2);
int		str_ms(char **dest, char *src);
int		str_ts(char **dest, char *set);
void	add_sl(char ***sl, char *val);
void	clear_sl(char **sl);
void	parse_map(t_cub3d *cub3d, char *path);

void	verify_map_line(t_cub3d *cub3d, char *line, int end);

#endif
