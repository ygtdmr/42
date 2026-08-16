/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_default_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 12:53:56 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/18 12:54:40 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*get_default_path(char c)
{
	if (c == '1')
		return ("textures/wall.xpm");
	else if (c == '0')
		return ("textures/fs.xpm");
	else if (c == 'C')
		return ("textures/col.xpm");
	else if (c == 'E')
		return ("textures/exit_0.xpm");
	else if (c == 'P')
		return ("textures/player.xpm");
	return (0);
}
