/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy_ft_memmove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:51:17 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/04 00:38:14 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".test.h"
#include "../libft/libft.h"

static void	test_1(void)
{
	char	i_cpy[] = "abcdef";
	char	i_move[] = "abcdef";

	test(TEST_STR, 1, ft_memcpy(i_cpy + 2, i_cpy, 4) - 2);
	test(TEST_STR, 1, ft_memmove(i_move + 2, i_move, 4) - 2);
}

int	main(void)
{
	test_1();
	return (0);
}
