/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:30:05 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/14 15:57:59 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	verify_line_end(t_cub3d *cub3d, char *line)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (!(line[i] == '1' || \
(line[i] == ' ' && (!i || (!line[i + 1] || line[i + 1] == '\n')))))
			exit_err(cub3d, "invalid map: map must surround with wall", 0);
		i++;
	}
}

void	verify_map_line(t_cub3d *cub3d, char *line, int end)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (end && ++i)
			verify_line_end(cub3d, line);
		else if (line[i] == '0' || line[i] == '1' || line[i] == ' ' || \
line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			if ((!i || (!line[i + 1] || line[i + 1] == '\n')) && \
line[i] != '1')
				exit_err(cub3d, "invalid map: map must surround with wall", 0);
			i++;
		}
		else
		{
			line[1] = 0;
			exit_err(cub3d, "invalid map: invalid char", line);
		}
	}
}
