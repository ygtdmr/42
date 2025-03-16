/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:23:27 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/16 17:51:19 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	all_wall(char *line)
{
	while (*line && *line != '\n')
	{
		if (*line++ != '1')
			return (0);
	}
	return (1);
}

static int	se_wall(char *line)
{
	int	start;
	int	end;

	start = *line == '1';
	while (*line && *line != '\n')
		line++;
	end = *(line - 1) == '1';
	return (start && end);
}

static int	map_width(char *line)
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

void	map_verifiy(t_sldata *sld, int mfd)
{
	char		*line;
	int			end_wall;
	int			lp;
	int			le;

	lp = 0;
	le = 0;
	line = get_next_line(mfd);
	if (!line)
		exit_sl(sld, "Error: map file is empty.\n", 1);
	if (!all_wall(line))
		(free(line), exit_sl(sld, "Error: map first line must be wall\n", 1));
	sld->mw = map_width(line);
	while (line)
	{
		sld->mh++;
		if (sld->mw != map_width(line) || !isvc(line) || !se_wall(line))
			return (free(line), 0);
		lp += str_clen(line, 'P');
		le += str_clen(line, 'E');
		sld->col += str_clen(line, 'C');
		free(line);
		line = get_next_line(mfd);
		if (line)
			end_wall = all_wall(line);
	}
	if (!end_wall)
		exit_sl(sld, "Error: map last line must be wall\n", 1);
	if (lp != 1)
		exit_sl(sld, "Error: player count shuld be 1\n", 1);
	if (le != 1)
		exit_sl(sld, "Error: exit count shuld be 1\n", 1);
	if (!sld->col)
		exit_sl(sld, "Error: col must greather than 0\n", 1);
}
