/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:30:02 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/02 13:46:42 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	splitlen(char const *s, char c)
{
	int	l;
	int	is_sep;

	l = 0;
	is_sep = 1;
	if (!s || *s == 0)
		return (0);
	while (*s != 0)
	{
		if (*s != c)
		{
			if (is_sep)
			{
				l++;
				is_sep = 0;
			}
		}
		else
			is_sep = 1;
		s++;
	}
	return (l);
}

static int	strclen(char const *s, char c)
{
	int	l;

	l = 0;
	while (*s != c && *(s++) != 0)
		l++;
	return (l);
}

static void	free_split(char **sp, int lsp)
{
	while (lsp--)
		free(sp[lsp]);
	free(sp);
}

char	**ft_split(char const *s, char c)
{
	char	**sp;
	int		isplt;
	int		lsplt;
	int		lssplt;

	isplt = 0;
	lsplt = splitlen(s, c) + 1;
	sp = (char **) ft_calloc(lsplt, sizeof(char *));
	if (!sp)
		return (0);
	while (*s != 0)
	{
		if (*s == c && s++)
			continue ;
		lssplt = strclen(s, c);
		sp[isplt] = (char *) ft_calloc(lssplt + 1, sizeof(char));
		if (!sp[isplt])
		{
			free_split(sp, lsplt);
			return (0);
		}
		ft_strlcpy(sp[isplt++], s, lssplt + 1);
		s += lssplt;
	}
	return (sp);
}
