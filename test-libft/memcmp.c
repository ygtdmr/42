/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:51:17 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/04 01:15:09 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".test.h"
#include "../libft/libft.h"

static void	test_1(void)
{
	t_obj	obj_1;
	t_obj	obj_2;

	obj_1.i = 2;
	obj_1.c = 'a';

	obj_2.i = 2;
	obj_2.c = 'a';

	//test(TEST_INT, 1, ft_memcmp(&obj_1, &obj_2, 2));
	test(TEST_INT, 1, *(((char *) &obj_2) + 3));
}

int	main(void)
{
	test_1();
	return (0);
}
