/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:19:23 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/18 13:03:12 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".test.h"
#include "../get_next_line/get_next_line.h"

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);
	static char s[16];

	printf("r=%s", get_next_line(fd));
	read(fd, s, 16);
	printf("s=%s\n", s);

	return (0);
}
