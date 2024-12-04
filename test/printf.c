/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:19:23 by yidemir           #+#    #+#             */
/*   Updated: 2024/12/04 19:50:38 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".test.h"
#include "../ft_printf/ft_printf.h"


int	main(void)
{
	printf("|%3.4d|\n", 12);
	printf("|%20.3s|\n", "test");
	printf("|%-20.5x|\n", 128);

	return (0);
	// printf("|%010d|\n", 42);
	// printf("|%#x|\n", 42);
	// printf("|%.0f|\n", 429.4);

	//printf(" %s", "");
	//printf(" %lx ", __LONG_MAX__);
	//ft_printf(" %x ", __LONG_MAX__);

	//int r1 = print(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	//printf("results r1=%i, r2=%i\n", r1, r2);

	//ft_printf("hello worl%sdeneme\n", "test");
	//ft_printf("%p", NULL);

	// printf("value is=%c str=%s main\n", 't', "test string");
	// ft_printf("value is=%c str=%s main\n", 't', "test string");
	// int i;
	// i = 10;
	// printf("(original)	pointer is=%p\n", &i);
	// ft_printf("		pointer is=%p\n", &i);



	
	printf("(original)	int number is with d=%d, with i=%i\n", -256, -256);
	ft_printf("		int number is with d=%d, with i=%i\n", -256, -256);

	printf("(original)	int number is with d=%d, with i=%i\n", 512, 512);
	ft_printf("		int number is with d=%d, with i=%i\n", 512, 512);

	return (0);

	//printf("(original)	long number is with d=%li,\n", -128L);
	
	//printf("(original)	int number is with d=%d, with i=%i\n", -2147483648, -2147483648);
	 ft_printf("		int number is with d=%d, with i=%i\n", -2147483649, -2147483649);

	printf("(original)	unsigned int=%u\n", -128);
	ft_printf("		unsigned int=%u\n", -128);

	printf("(original)	lower x=%x\n", -128);
	ft_printf("		lower x=%x\n", -128);

	printf("(original)	upper x=%X\n", -128);
	ft_printf("		upper x=%X\n", -128);

	printf("(original)	escape=%%\n");
	ft_printf("		escape=%%\n");

	printf("(original)	sci lower=%e\n", 12.345);
	ft_printf("		sci lower=%e\n", 12.345);

	printf("(original)	sci upper=%E\n", 12.345);
	ft_printf("		sci upper=%E\n", 12.345);

	printf("(original)	sci or dbl=%g\n", 1234567.89);
	ft_printf("		sci or dbl=%g\n", 1234567.89);

	printf("(original)	sci or dbl upper=%G\n", 1234567.89);
	ft_printf("		sci or dbl upper=%G\n", 1234567.89);

	printf("(original)	octal=%o\n", 64);
	ft_printf("		octal=%o\n", 64);

	printf("(original)	double or float=%f\n", 12.543);
	ft_printf("		double or float=%f\n", 12.543);

	int count_org;
	int count;
	int count_org_2;
	int count_2;

	printf("(original)	");
	printf("total count%nnext%n\n", &count_org, &count_org_2);
	ft_printf("\t\t");
	ft_printf("total count%nnext%n\n", &count, &count_2);

	printf("(original) result=%i, result=%i\n", count_org, count);
	printf("next (original) result=%i, result=%i\n", count_org_2, count_2);

	

	return (0);
}
