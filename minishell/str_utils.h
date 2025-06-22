/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 16:14:09 by yidemir           #+#    #+#             */
/*   Updated: 2025/06/22 15:46:29 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_UTILS_H
# define STR_UTILS_H

# include "libft/libft.h"

int		str_match(char *dest, char *src);
char	*str_lrealloc(char *dest, char *src, size_t length, int src_free);
void	str_lclean(char **dest, size_t length);
int		str_mc(char **dest, char *needle);

#endif
