/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:08:49 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/07 13:47:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_img(t_cub3d *cub3d, char *line, void **img)
{
	char	*path;

	path = ft_strtrim(line, " \n");
	*img = mlx_xpm_file_to_image(cub3d->mlx, path, 0, 0);
	free(path);
	if (!*img)
		exit_err(cub3d, strerror(errno), line);
}

static void	get_rgb(t_cub3d *cub3d, int *rgb, char **line)
{
	int	step;
	int	value;

	step = 2;
	*rgb = 0;
	while (1)
	{
		str_ts(line, " \n");
		if (!*(*line))
			return (exit_err(cub3d, "invalid rgb", "missing value"));
		if (!ft_isdigit(*(*line)))
			return (exit_err(cub3d, "invalid rgb", (*line)));
		value = ft_atoi((*line));
		if (value > 255)
			return (exit_err(cub3d, "invalid rgb: max 255", (*line)));
		*rgb |= value << (8 * step);
		str_ts(line, "0123456789");
		str_ts(line, " \n");
		step--;
		if (*(*line) && (step == -1 || !str_ts(line, ",")))
			return (exit_err(cub3d, "invalid rgb", (*line)));
		if (step == -1)
			break ;
	}
}

static void	get_config(t_cub3d *cub3d, t_map *map, int fd)
{
	char	*line;

	map->tmp = get_next_line(fd);
	line = map->tmp;
	while (*line)
	{
		str_ts(&line, " \n");
		if (str_ms(&line, "NO "))
			get_img(cub3d, line, &map->img_no);
		else if (str_ms(&line, "SO "))
			get_img(cub3d, line, &map->img_so);
		else if (str_ms(&line, "WE "))
			get_img(cub3d, line, &map->img_we);
		else if (str_ms(&line, "EA "))
			get_img(cub3d, line, &map->img_ea);
		else if (str_ms(&line, "F "))
			get_rgb(cub3d, &map->rgb_f, &line);
		else if (str_ms(&line, "C "))
			get_rgb(cub3d, &map->rgb_c, &line);
		else if (*line)
			exit_err(cub3d, "invalid config: invalid value", line);
		map->tmp = get_next_line(fd);
		line = map->tmp;
	}
	exit_err(cub3d, "invalid config", "missing paths");
}

void	parse_map(t_cub3d *cub3d, char *path)
{
	t_map	*map;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_err(cub3d, strerror(errno), path);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		exit_err(cub3d, "malloc", 0);
	map->rgb_f = -1;
	map->rgb_c = -1;
	cub3d->map = map;
	get_config(cub3d, map, fd);
}
