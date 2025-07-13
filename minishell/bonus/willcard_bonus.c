/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   willcard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 06:54:45 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/12 07:38:03 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expand_bonus.h"
#include "str_utils_bonus.h"

static int	willcard_match(char *d_name, char *wb, char *wa)
{
	char	*tmp;
	int		m_wb;
	int		m_wa;

	m_wb = !*wb || ft_strnstr(d_name, wb, ft_strlen(wb));
	m_wa = !*wa;
	if (!m_wa)
	{
		tmp = ft_strnstr(d_name, wa, ft_strlen(d_name));
		m_wa = tmp && !*(tmp + ft_strlen(wa));
	}
	return (m_wb && m_wa);
}

static void	willcard_expand(char **out, char *wb, char *wa)
{
	char			*cwd;
	DIR				*dir;
	struct dirent	*drn;

	cwd = getcwd(0, 0);
	dir = opendir(cwd);
	free(cwd);
	while (1)
	{
		drn = readdir(dir);
		if (!drn)
			break ;
		if (*(drn->d_name) == '.')
			continue ;
		if (willcard_match(drn->d_name, wb, wa))
		{
			if (*out && **out)
				*out = str_lrealloc(*out, " ", 1, 0);
			*out = str_lrealloc(*out, drn->d_name, ft_strlen(drn->d_name), 0);
		}
	}
	closedir(dir);
}

int	willcard_append(char **raw, char **out)
{
	char	*wb;
	char	*wa;
	char	*str;
	int		length;

	str = 0;
	length = ft_strlen(*raw) - ft_strlen(ft_strchr(*raw, '*'));
	wb = str_lrealloc(0, *raw, length, 0);
	length = ft_strlen(ft_strrchr(*raw, '*') + 1);
	wa = str_lrealloc(0, ft_strrchr(*raw, '*') + 1, length, 0);
	willcard_expand(&str, wb, wa);
	if (str)
	{
		*out = str_lrealloc(*out, str, ft_strlen(str), 1);
		free(wa);
		free(wb);
		length = 0;
		while ((*raw)[length] && is_rawchar((*raw)[length]))
			length++;
		str_lclean(raw, length);
		return (1);
	}
	return (0);
}
