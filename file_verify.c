/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fie_verify.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 13:09:08 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/18 13:09:28 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	file_verify(char *s)
{
	char	*e;

	while (ft_strnstr(s, "./", 2) || ft_strnstr(s, "../", 3))
	{
		if (ft_strnstr(s, "./", 2))
			s = s + 2;
		else if (ft_strnstr(s, "../", 3))
			s = s + 3;
	}
	e = ft_strrchr(s, '/');
	if ((e && *(e + 1) == '.') || *s == '.')
		exit_sl(0, "Error: file should not be hidden file.\n", 1);
	e = ft_strnstr(s, ".ber", ft_strlen(s));
	if (!e || *(e + 4) != 0)
		exit_sl(0, "Error: file extension should be \".ber\"\n", 1);
}
