/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:18:32 by yidemir           #+#    #+#             */
/*   Updated: 2025/03/18 14:18:33 by yidemir          ###   ########.fr       */
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
		isac = (isac || (*line == 'N'));
		if (!isac)
			return (0);
		line++;
	}
	return (1);
}
