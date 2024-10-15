/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:25:45 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/11 16:42:41 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	int	is_upper;
	int	is_lower;
	int	is_alpha;
	int	is_digit;

	is_upper = (c >= 65 && c <= 90);
	is_lower = (c >= 97 && c <= 122);
	is_alpha = (is_upper || is_lower);
	is_digit = (c >= 48 && c <= 57);
	return (is_alpha || is_digit);
}
