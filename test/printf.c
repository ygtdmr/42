/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 22:19:23 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/24 17:59:53 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include ".test.h"
#include "../ft_printf/libftprintf.h"

int	main(void)
{
	ft_printf("value is=%c str=%s main\n", 't', "test string");
	int i;
	i = 10;
	printf("(original)	pointer is=%p\n", &i);
	ft_printf("		pointer is=%p\n", &i);
	
	printf("(original)	int number is with d=%d, with i=%i\n", -128, -128);
	ft_printf("		int number is with d=%d, with i=%i\n", -128, -128);

	printf("(original)	unsigned int=%u\n", (unsigned) -128);
	ft_printf("		unsigned int=%u\n", (unsigned) -128);

	printf("(original)	lower x=%x\n", -128);
	ft_printf("		lower x=%x\n", -128);

	printf("(original)	upper x=%X\n", -128);
	ft_printf("		upper x=%X\n", -128);

	printf("(original)	escape=%%\n");
	ft_printf("		escape=%%\n");

	return (0);
}
