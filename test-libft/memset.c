/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 15:51:17 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/03 23:51:10 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".test.h"
#include "../libft/libft.h"

static void	test_1(void)
{
	char	*i;

	i = (char *) malloc(3 * sizeof(char));

	ft_memset(((char *) i), 0, 4);
	ft_memset(((char *) i), 65, 1);

	i++;
	ft_memset(((char *) i), 0, 4);
	ft_memset(((char *) i), 108, 1);

	i++;
	ft_memset(((char *) i), 0, 4);
	ft_memset(((char *) i), 105, 1);

	i -= 2;

	test(TEST_STR, 1, i);
}

static void	test_2(void)
{
	t_obj	obj;

	obj.c = 'T';
	obj.i = 12;

	ft_memset((char *) &obj, 0, 4);

	test(TEST_CHAR, 1, obj.c);
	test(TEST_INT, 1, obj.i);
}

static void	test_3(void)
{
	int	i;

	i = 2048;

	ft_memset((char *) &i, 32, 1);

	test(TEST_INT, 1, i);
}

static void	test_4(void)
{
	long i[] = {21, 41, 12, 54};

	ft_memset(((char *) i) + 8, 255, 8);
	ft_memset((((char *) i) + 8), 211, 1);

	test(TEST_INT, 1, i[1]);
}

int	main(void)
{
	test_1();
	testnl();
	test_2();
	testnl();
	test_3();
	testnl();
	test_4();
	return (0);
}
