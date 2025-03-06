/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:01:25 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/06 16:42:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	sl_error()
{
	write(2, "Error\n", 6);
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
	sld.map = get_map(&sld, open(argv[1], O_RDONLY));
	sld.mlx = mlx_init();
	sld.win = mlx_new_window(sld.mlx, sld.mw * 64, sld.mh * 64, "push_swap");
	mlx_hook(sld.win, 17, 0, exit_sl, &sld);
	mlx_key_hook(sld.win, handle_keyhook, &sld);
	map_render(&sld);
	mlx_loop(sld.mlx);
	free(sld.mlx);
}
