/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 13:40:28 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/27 16:35:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include ".test/test.h"

static void	exit_cub3d(t_cub3d *cub3d, int err)
{
	if (cub3d)
	{
		clear_map(cub3d);
		if (cub3d->mlx)
		{
			if (cub3d->container.mlx_img)
				mlx_destroy_image(cub3d->mlx, cub3d->container.mlx_img);
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

int	close_window(t_cub3d *cub3d)
{
	exit_cub3d(cub3d, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	if (argc != 2)
		exit_err(0, "argument count should be 2", 0);
	file_verify(argv[1]);
	ft_bzero(&cub3d, sizeof(t_cub3d));
	cub3d.mlx = mlx_init();
	if (!cub3d.mlx)
		exit_err(0, "mlx_init", 0);
	parse_map(&cub3d, argv[1]);
	mlx_get_screen_size(cub3d.mlx, &cub3d.width, &cub3d.height);
	cub3d.width /= 2;
	cub3d.height /= 2;
	cub3d.win = mlx_new_window(cub3d.mlx, cub3d.width, cub3d.height, "Cub3D");
	if (!cub3d.win)
		exit_err(&cub3d, "mlx_new_window", 0);
	cub3d.container = new_img(cub3d.mlx, 0, cub3d.width, cub3d.height);
	mlx_hook(cub3d.win, 17, 0, close_window, &cub3d);
	mlx_hook(cub3d.win, 2, 1, handle_key_press, &cub3d);
	mlx_hook(cub3d.win, 3, 2, handle_key_release, &cub3d);
	// mlx_loop_hook(cub3d.mlx, render, &cub3d);
	render(&cub3d);
	mlx_loop(cub3d.mlx);
	return (0);
}
