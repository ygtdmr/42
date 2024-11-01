/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 23:30:02 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/30 23:57:14 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	splitlen(char const *s, char c)
{
	int	l;
	int	isc;

	if (!s)
		return (0);
	l = 0;
	isc = 1;
	while (*s)
	{
		if (*s != c)
			isc = 0;
		if (*s == c && *(s + 1) != c && *(s + 1) != 0 && !isc)
		{
			isc = 1;
			l++;
		}
		s++;
	}
	return (l + 1);
}

static int	strclen(char const *s, char c)
{
	int	l;

	l = 0;
	while (*s != c && *s++)
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
	while (*s)
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
