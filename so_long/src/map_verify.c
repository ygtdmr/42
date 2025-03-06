/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:23:27 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/06 15:52:34 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	all_wall(char *line)
{
	while (*line && *line != '\n')
	{
		if (*line++ != '1')
			return (0);
	}
	return (1);
}

static int	start_end_wall(char *line)
{
	int	start;
	int	end;

	start = *line == '1';
	while (*line && *line != '\n')
		line++;
	end = *(line - 1) == '1';
	return (start && end);
}

static int	inc_chars(char *line)
{
	int	isac;

	while (*line && *line != '\n')
	{
		isac = 0;
		isac = *line == '0';
		isac = (isac || (*line == '1'));
		isac = (isac || (*line == 'C'));
		isac = (isac || (*line == 'E'));
		isac = (isac || (*line == 'P'));
		if (!isac)
			return (0);
		line++;
	}
	return (1);
}

int	map_width(char *line)
{
	int	w;

	w = 0;
	while (*line && *line != '\n')
	{
		w++;
		line++;
	}
	return (w);
}

int	map_verifiy(t_sldata *sld, int mfd)
{
	char		*line;
	int			end_wall;
	int			player;

	player = 0;
	line = get_next_line(mfd);
	if (!line || !all_wall(line))
		return (0);
	sld->mw = map_width(line);
	while (line)
	{
		sld->mh++;
		if ((sld->mw != map_width(line)))
			return (0);
		if (!inc_chars(line) || !start_end_wall(line))
			return (0);
		player += (ft_strchr(line, 'P') != 0);
		sld->col += (ft_strchr(line, 'C') != 0);
		sld->exit += (ft_strchr(line, 'E') != 0);
		free(line);
		line = get_next_line(mfd);
		if (line)
			end_wall = all_wall(line);
	}
	return (sld->col && sld->exit == 1 && end_wall && player == 1);
}
