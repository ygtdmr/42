/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 21:14:37 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/07 14:06:45 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "executer.h"
#include "expand.h"

char	*path_resolve(char *file)
{
	char	**paths;
	char	*abs_path;

	if (access(file, X_OK) == 0)
		return (ft_strdup(file));
	abs_path = 0;
	paths = ft_split(getenv("PATH"), ':');
	while (paths && *paths)
	{
		abs_path = ft_strdup(*paths);
		abs_path = str_lrealloc(abs_path, "/", 1);
		abs_path = str_lrealloc(abs_path, file, ft_strlen(file));
		if (access(abs_path, X_OK) == 0)
		{
			while (paths && *paths)
				free(*paths++);
			free(paths);
			return (abs_path);
		}
		free(abs_path);
		free(*paths++);
	}
	return (0);
}
