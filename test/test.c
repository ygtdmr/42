/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:19:23 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/15 17:11:26 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".test.h"
#include "../get_next_line/get_next_line.h"

int	main(void)
{
	int fd = open("test.txt", O_RDONLY);

	test(TEST_STR, 1, get_next_line(fd));
	test(TEST_STR, 1, get_next_line(fd));
	test(TEST_STR, 1, get_next_line(fd));
	test(TEST_STR, 1, get_next_line(fd));
	test(TEST_STR, 1, get_next_line(fd));

	return (0);
}
