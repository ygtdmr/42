/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:06:07 by yidemir           #+#    #+#             */
/*   Updated: 2024/10/31 23:13:30 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		l;
	t_list	*nlst;

	if (!lst)
		return (0);
	nlst = lst->next;
	l = 1;
	while (nlst)
	{
		l++;
		nlst = nlst->next;
	}
	return (l);
}
