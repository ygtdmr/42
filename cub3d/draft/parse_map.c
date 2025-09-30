/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:08:49 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/27 14:58:55 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_img(t_cub3d *cub3d, char *line, t_img *img)
{
	char	*path;

	if (img->mlx_img)
		exit_err(cub3d, "invalid config: img already defined", line);
	path = ft_strtrim(line, " \n");
	*img = new_img(cub3d->mlx, path, IMG_SIZE, IMG_SIZE);
	if (!img->mlx_img)
	{
		if (cub3d->map.tmp)
			free(cub3d->map.tmp);
		cub3d->map.tmp = path;
		exit_err(cub3d, strerror(errno), path);
	}
	free(path);
}

static void	get_rgb(t_cub3d *cub3d, int *rgb, char **line)
{
	int	step;
	int	value;

	step = 2;
	if (*rgb != -1)
		exit_err(cub3d, "invalid config: rgb already defined", *line);
	*rgb = 0;
	while (step != -1)
	{
		str_cs(line, " \n");
		if (!*(*line))
			return (exit_err(cub3d, "invalid rgb", "missing value"));
		if (!ft_isdigit(*(*line)))
			return (exit_err(cub3d, "invalid rgb", (*line)));
		value = ft_atoi((*line));
		if (value > 255)
			return (exit_err(cub3d, "invalid rgb: max 255", (*line)));
		*rgb |= value << (8 * step);
		str_cs(line, "0123456789");
		str_cs(line, " \n");
		step--;
		if (*(*line) && (step == -1 || !str_cs(line, ",")))
			return (exit_err(cub3d, "invalid rgb", (*line)));
	}
}

static void	get_config(t_cub3d *cub3d, t_map *map, int fd)
{
	char	*line;

	map->tmp = get_next_line(fd);
	if (!map->tmp || (map->rgb_f != -1 && map->rgb_c != -1 && \
map->img_no.mlx_img && map->img_so.mlx_img && \
map->img_we.mlx_img && map->img_ea.mlx_img))
		return ;
	line = map->tmp;
	str_cs(&line, " \n");
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
		if (str_setonly(map->tmp, " \n") && ++nl)
			free(map->tmp);
		else
		{
			if (map->content && nl)
				exit_err(cub3d, "invalid map: separated with newline", 0);
			nl = 0;
			if (!str_setonly(map->tmp, " 01NSEW\n"))
				exit_err(cub3d, "invalid map: invalid char", map->tmp);
			add_sl(&map->content, map->tmp);
		}
		map->tmp = get_next_line(fd);
	}
	if (!map->content)
		exit_err(cub3d, "invalid map: empty content", 0);
	map->tmp = dup_sl(map->content);
	scan_map_content(cub3d, map->tmp);
	clear_sl(map->tmp);
	map->tmp = 0;
}

void	parse_map(t_cub3d *cub3d, char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_err(cub3d, strerror(errno), path);
	cub3d->map.rgb_f = -1;
	cub3d->map.rgb_c = -1;
	get_config(cub3d, &cub3d->map, fd);
	if (!(cub3d->map.rgb_f != -1 && cub3d->map.rgb_c != -1 && \
cub3d->map.img_no.mlx_img && cub3d->map.img_so.mlx_img && \
cub3d->map.img_we.mlx_img && cub3d->map.img_ea.mlx_img))
		exit_err(cub3d, "invalid config", "missing config values");
	get_content(cub3d, &cub3d->map, fd);
}
