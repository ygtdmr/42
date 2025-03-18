/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:01:25 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/18 16:30:55 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	close_window(t_sldata *sld)
{
	exit_sl(sld, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sldata	sld;

	if (argc == 1)
		exit_sl(0, "Error: map path should be not empty.\n", 1);
	else if (argc > 2)
		exit_sl(0, "Error: only enter one argument.\n", 1);
	ft_memset(&sld, 0, sizeof(sld));
	file_verify(argv[1]);
	map_verifiy(&sld, open(argv[1], O_RDONLY));
	map_verify_path(&sld, get_map(&sld, open(argv[1], O_RDONLY)));
	sld.map = get_map(&sld, open(argv[1], O_RDONLY));
	sld.mlx = mlx_init();
	verify_default_images(&sld);
	sld.win = mlx_new_window(sld.mlx, sld.mw * 64, sld.mh * 64, "push_swap");
	mlx_hook(sld.win, 17, 0, close_window, &sld);
	mlx_key_hook(sld.win, handle_keyhook, &sld);
	map_render(&sld);
	mlx_loop(sld.mlx);
	return (0);
}
