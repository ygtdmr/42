/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:40:28 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/10 11:44:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	exit_cub3d(t_cub3d *cub3d, int err)
{
	if (cub3d)
	{
		clear_map(cub3d);
		if (cub3d->mlx)
		{
			if (cub3d->win)
				mlx_destroy_window(cub3d->mlx, cub3d->win);
			mlx_destroy_display(cub3d->mlx);
			free(cub3d->mlx);
		}
	}
	exit(err);
}

void	exit_err(t_cub3d *cub3d, char *msg1, char *msg2)
{
	int	has_endl;

	has_endl = msg1[ft_strlen(msg1) - 1] == '\n';
	ft_putstr_fd("Error: ", 2);
	ft_putstr_fd(msg1, 2);
	if (msg2)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg2, 2);
		has_endl = msg2[ft_strlen(msg2) - 1] == '\n';
	}
	if (!has_endl)
		ft_putstr_fd("\n", 2);
	exit_cub3d(cub3d, 1);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	if (argc != 2)
		exit_err(0, "argument count should be 2", 0);
	ft_bzero(&cub3d, sizeof(t_cub3d));
	cub3d.mlx = mlx_init();
	if (!cub3d.mlx)
		exit_err(0, "mlx_init", 0);
	parse_map(&cub3d, argv[1]);
	cub3d.win = mlx_new_window(cub3d.mlx, 512, 512, "Cub3D");
	if (!cub3d.win)
		exit_err(&cub3d, "mlx_new_window", 0);
	printf("img_no=|%p|\nimg_so=|%p|\nimg_we=|%p|\nimg_ea=|%p|\n\
f=(r=%d,g=%d,b=%d)\nc=(r=%d,g=%d,b=%d)\n", \
cub3d.map->img_no, cub3d.map->img_so, cub3d.map->img_we, cub3d.map->img_ea, \
(cub3d.map->rgb_f >> 16) & 255, (cub3d.map->rgb_f >> 8) & 255, cub3d.map->rgb_f & 255, \
(cub3d.map->rgb_c >> 16) & 255, (cub3d.map->rgb_c >> 8) & 255, cub3d.map->rgb_c & 255);
	
int i = 0;
printf("map content:\n");
while (cub3d.map->content[i])
	printf("%s", cub3d.map->content[i++]);
exit_cub3d(&cub3d, 0);
	// mlx_loop(sld.mlx);
	return (0);
}
