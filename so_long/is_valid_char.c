/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:21:17 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/18 14:21:18 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid_char(char *line)
{
	int	isac;

	while (*line && *line != '\n')
	{
		isac = *line == '0';
		isac = (isac || (*line == '1'));
		isac = (isac || (*line == 'C'));
		isac = (isac || (*line == 'E'));
		isac = (isac || (*line == 'P'));
		if (!isac)
			return (0);
		line++;
	}
	return (1);
}
