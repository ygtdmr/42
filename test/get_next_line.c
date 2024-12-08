/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 21:50:27 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/05 22:08:45 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".test.h"

int	main(void)
{
	char buffer[128];

	int fd = open("test.txt", O_RDONLY);
	read(fd, buffer, sizeof(buffer));
	buffer[11] = 0;
	test(TEST_STR, 1, buffer);

	return (0);
}
