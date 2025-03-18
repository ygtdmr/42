/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:23:27 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/18 14:20:36 by yidemir          ###   ########.fr       */
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

	if (*line != '\n')
	{
		start = *line == '1';
		while (*line && *line != '\n')
			line++;
		end = *(line - 1) == '1';
		return (start && end);
	}
	return (0);
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

static void	init_data(t_sldata *sld, int mfd, t_slverify *slvfy)
{
	char	*line;
	int		end_wall;

	line = get_next_line(mfd);
	slvfy->is_map_empty = !line;
	if (slvfy->is_map_empty)
		return ;
	slvfy->is_border_wall = all_wall(line);
	sld->mw = map_width(line);
	while (line)
	{
		sld->mh++;
		slvfy->is_same_w = (slvfy->is_same_w && sld->mw == map_width(line));
		slvfy->is_valid_char = (slvfy->is_valid_char && is_valid_char(line));
		slvfy->is_border_wall = (slvfy->is_border_wall && se_wall(line));
		slvfy->l_player += str_clen(line, 'P');
		slvfy->l_exit += str_clen(line, 'E');
		sld->col += str_clen(line, 'C');
		free(line);
		line = get_next_line(mfd);
		if (line)
			end_wall = all_wall(line);
	}
	slvfy->is_border_wall = (slvfy->is_border_wall && end_wall);
}

void	map_verifiy(t_sldata *sld, int mfd)
{
	t_slverify	slvfy;

	ft_memset(&slvfy, 0, sizeof(slvfy));
	slvfy.is_same_w = 1;
	slvfy.is_valid_char = 1;
	slvfy.is_border_wall = 1;
	init_data(sld, mfd, &slvfy);
	if (mfd == -1)
		exit_sl(sld, "Error: map file not found.\n", 1);
	else if (slvfy.is_map_empty)
		exit_sl(sld, "Error: map file is empty.\n", 1);
	else if (!slvfy.is_valid_char)
		exit_sl(sld, "Error: invalid character exists in the map.\n", 1);
	else if (!slvfy.is_same_w)
		exit_sl(sld, "Error: width of map lines are not equal.\n", 1);
	else if (!slvfy.is_border_wall)
		exit_sl(sld, "Error: map border must be wall.\n", 1);
	else if (slvfy.l_player != 1)
		exit_sl(sld, "Error: player count shuld be 1.\n", 1);
	else if (slvfy.l_exit != 1)
		exit_sl(sld, "Error: exit count shuld be 1.\n", 1);
	else if (sld->col == 0)
		exit_sl(sld, "Error: col must greather than 0.\n", 1);
}
