/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:15:05 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/03 22:48:01 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define TEST_INT	0
#define TEST_CHAR	1
#define TEST_STR	2

typedef struct s_obj
{
	char	c;
	int		i;
}	t_obj;

void	test(int type, int count, ...)
{
	va_list	args;

	va_start(args, count);
	while (count--)
	{
		if (type == TEST_INT)
			printf("result=%i\n", va_arg(args, int));
		else if (type == TEST_CHAR)
			printf("result=%c\n", va_arg(args, int));
		else if (type == TEST_STR)
			printf("result=%s\n", va_arg(args, char *));
	}
	va_end(args);
}

void	testnl(void)
{
	printf("\n");
}
