/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 06:36:04 by yidemir           #+#    #+#             */
/*   Updated: 2025/08/14 13:45:58 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	str_swap(char **x, char **y)
{
	char	*tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

int	is_varchar(char *s, size_t i)
{
	if (!i)
		return (ft_isalpha(s[i]) || s[i] == '_');
	else
		return (ft_isalnum(s[i]) || s[i] == '_');
}

void	clear_sl(char **sl)
{
	size_t	i;

	if (!sl)
		return ;
	i = 0;
	while (sl[i])
		free(sl[i++]);
	free(sl);
}

int	sl_count(char **sl)
{
	size_t	i;

	i = 0;
	while (sl[i])
		i++;
	return (i);
}
