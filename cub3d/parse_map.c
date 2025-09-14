/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:08:49 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/14 17:51:37 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_img(t_cub3d *cub3d, char *line, void **img)
{
	int		size;
	char	*path;

	size = IMG_SIZE;
	path = ft_strtrim(line, " \n");
	*img = mlx_xpm_file_to_image(cub3d->mlx, path, &size, &size);
	if (!*img)
	{
		if (cub3d->map->tmp)
			free(cub3d->map->tmp);
		cub3d->map->tmp = path;
		exit_err(cub3d, strerror(errno), path);
	}
	else
		free(path);
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
	if (!map->tmp || (map->img_no && map->img_so && map->img_we && \
map->img_ea && map->rgb_f != -1 && map->rgb_c != -1))
		return ;
	line = map->tmp;
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
	free(map->tmp);
	get_config(cub3d, map, fd);
}

static void	get_content(t_cub3d *cub3d, t_map *map, int fd)
{
	int	nl;

	nl = 0;
	while (map->tmp)
	{
		if (*(map->tmp) == '\n')
		{
			nl = 1;
			free(map->tmp);
		}
		else
		{
			if (map->content && nl)
				exit_err(cub3d, "invalid map: empty newline", 0);
			nl = 0;
			validate_map_line(cub3d, map->tmp);
			add_sl(&map->content, map->tmp);
		}
		map->tmp = get_next_line(fd);
	}
	if (!map->content)
		exit_err(cub3d, "invalid map: empty content", 0);
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
	if (!(map->img_no && map->img_so && map->img_we && map->img_ea && \
map->rgb_f != -1 && map->rgb_c != -1))
		exit_err(cub3d, "invalid config", "missing config values");
	get_content(cub3d, map, fd);
}
