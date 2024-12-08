/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjcf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 01:02:18 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/06 22:23:22 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjcf(char c, char *s2, int end)
{
	char	*sc;
	char	*temp;

	sc = ft_calloc(2, sizeof(char));
	*sc = c;
	if (end)
		temp = ft_strjoin(s2, sc);
	else
		temp = ft_strjoin(sc, s2);
	free(sc);
	free(s2);
	return (temp);
}
