/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .test.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:15:05 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/03 16:50:35 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEST_INT	0
#define TEST_CHAR	1
#define TEST_STR	2

void	test(int type, int count, ...)
{
	va_list	args;
	void	*value;

	va_start(args, count);

	while (count--)
	{
		if (type == TEST_INT)
		{
			*((int *) value) = va_arg(args, int);
			printf("result=%i\n", *((int *) value));
		}
		else if (type == TEST_CHAR)
		{
			*((char *) value) = (char) va_arg(args, int);
			printf("result=%c\n", *((char *) value));
		}
		else if (type == TEST_STR)
		{
			*((char **) value) = va_arg(args, char *);
			printf("result=%s\n", *((char **) value));
		}
	}
	va_end(args);
}
