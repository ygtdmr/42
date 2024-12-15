/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 00:54:02 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/15 15:56:42 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *s)
{
	size_t	l;

	l = 0;
	while (s && *s++)
		l++;
	return (l);
}

static void	gnl_strcpy(char *dst, char *src)
{
	if (!src)
		return ;
	while (*src)
		*dst++ = *src++;
	*dst = 0;
}

char	*gnl_readmem(int fd)
{
	char	bf[BUFFER_SIZE + 1];
	char	*bfmem;
	int		rb;

	rb = read(fd, bf, BUFFER_SIZE);
	if(rb <= 0)
		return (0);
	bf[rb] = 0;
	bfmem = (char *) malloc(rb * sizeof(char));
	if (!bfmem)
		return (0);
	gnl_strcpy(bfmem, bf);
	return (bfmem);
}

char	*gnl_line(char *bf, char c)
{
	char	*ns;
	int		lbf;

	lbf = ft_strlen(bf);
	ns = (char *) malloc((lbf + 2) * sizeof(char));
	if (!ns)
		return (0);
	gnl_strcpy(ns, bf);
	ns[lbf] = c;
	ns[lbf + 1] = 0;
	if (bf)
		free(bf);
	return(ns);
}
