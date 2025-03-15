/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:23:27 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/15 16:17:02 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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

int	map_verifiy(t_sldata *sld, int mfd)
{
	char		*line;
	int			end_wall;
	int			lp;
	int			le;

	lp = 0;
	le = 0;
	line = get_next_line(mfd);
	if (!line || !all_wall(line))
		return (free(line), 0);
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
	return (sld->col && end_wall && lp == 1 && le == 1);
}
