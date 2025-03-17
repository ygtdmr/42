/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:01:25 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/18 00:49:08 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	str_clen(char *s, char c)
{
	int	i;

	i = 0;
	while (*s++)
		i += (*s == c);
	return (i);
}

static int	verify_filename(char *s)
{
	char	*e;

	e = ft_strnstr(s, ".ber", ft_strlen(s));
	if (e)
	{
		if (*(e + 4) != 0)
			return (0);
		if (ft_strrchr(s, '/'))
		{
			s = (ft_strrchr(s, '/') + 1);
			return (ft_strlen(s) > 4);
		}
	}
	return (0);
}

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
		exit_sl(0, "Error: only enter one arguments\n", 1);
	ft_memset(&sld, 0, sizeof(sld));
	verify_filename(argv[1]);
	map_verifiy(&sld, open(argv[1], O_RDONLY));
	// map_verify_path(&sld, get_map(&sld, open(argv[1], O_RDONLY)));
	sld.map = get_map(&sld, open(argv[1], O_RDONLY));
	sld.mlx = mlx_init();
	sld.win = mlx_new_window(sld.mlx, sld.mw * 64, sld.mh * 64, "push_swap");
	mlx_hook(sld.win, 17, 0, close_window, &sld);
	mlx_key_hook(sld.win, handle_keyhook, &sld);
	map_render(&sld);
	mlx_loop(sld.mlx);
	return (0);
}
