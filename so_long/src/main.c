/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:01:25 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/04 18:56:04 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	sl_error()
{
	perror("Error");
	return (1);
}

int	main(int argc, char **argv)
{
	t_sldata	sld;

	if (argc == 1)
		return (sl_error());
	ft_memset(&sld, 0, sizeof(sld));
	if (!map_verifiy(&sld, open(argv[1], O_RDONLY)))
		return (sl_error());
	sld.map = get_map(&sld, argv[1]);
	sld.mlx = mlx_init();
	sld.win = mlx_new_window(sld.mlx, sld.mw * 64, sld.mh * 64, "push_swap");
	mlx_hook(sld.win, 17, 0, (int (*)()) exit, 0);
	mlx_hook(sld.win, 2, 0, handle_keyhook, 0);
	map_render(&sld);
	mlx_loop(sld.mlx);
}
