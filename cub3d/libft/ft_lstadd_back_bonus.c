/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:06:07 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/01 12:38:04 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nlst;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	nlst = *lst;
	while (nlst->next)
		nlst = nlst->next;
	nlst->next = new;
}
