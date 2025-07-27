/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iarslan <iarslan@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:14:09 by yidemir           #+#    #+#             */
/*   Updated: 2025/07/27 03:08:43 by iarslan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_UTILS_H
# define STR_UTILS_H

# include "libft/libft.h"

int		str_match(char *dest, char *src);
char	*str_lrealloc(char *dest, char *src, size_t length, int src_free);
void	str_lclean(char **dest, size_t length);
int		str_mc(char **dest, char *needle);
void	str_swap(char **x, char **y);

#endif
