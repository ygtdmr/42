/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:30:05 by yidemir           #+#    #+#             */
/*   Updated: 2025/09/14 17:59:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_map_line(t_cub3d *cub3d, char *line)
{
	while (line && *line && *line != '\n')
	{
		if (*line == '0' || *line == '1' || *line == ' ' || \
*line == 'N' || *line == 'S' || *line == 'E' || *line == 'W')
			line++;
		else
		{
			line[1] = 0;
			exit_err(cub3d, "invalid map: invalid char", line);
		}
	}
}
