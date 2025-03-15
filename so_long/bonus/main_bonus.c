/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:01:25 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/15 15:10:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	str_clen(char *s, char c)
{
	int	i;

	i = 0;
	while (*s++)
		i += (*s == c);
	return (i);
}

static int	sl_error(void)
{
	write(2, "Error\n", 6);
	return (1);
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
	return (exit_sl(sld, 0));
}

int	main(int argc, char **argv)
{
	t_sldata	sld;

	if (argc == 1)
		return (sl_error());
	ft_memset(&sld, 0, sizeof(sld));
	if (!map_verifiy(&sld, open(argv[1], O_RDONLY)))
		return (sl_error());
	if (!verify_filename(argv[1]))
		return (sl_error());
	if (!map_verify_path(&sld, get_map(&sld, open(argv[1], O_RDONLY))))
		return (sl_error());
	sld.map = get_map(&sld, open(argv[1], O_RDONLY));
	sld.mlx = mlx_init();
	sld.win = mlx_new_window(sld.mlx, sld.mw * 64, sld.mh * 64, "push_swap");
	mlx_hook(sld.win, 17, 0, close_window, &sld);
	mlx_key_hook(sld.win, handle_keyhook, &sld);
	map_render(&sld);
	mlx_string_put(sld.mlx, sld.win, 8, 16, 0xffffff, "Move count: 0");
	sld.el = enemy_init(&sld);
	mlx_loop_hook(sld.mlx, enemy_handle, &sld);
	mlx_loop(sld.mlx);
	mlx_destroy_window(sld.mlx, sld.win);
	mlx_destroy_display(sld.mlx);
	free(sld.mlx);
	return (0);
}
