/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:38:05 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/01 00:48:56 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ilst;

	ilst = *lst;
	if (!lst)
		return ;
	if (ilst->content)
		del(ilst->content);
	if (ilst->next)
		ft_lstclear(&ilst->next, del);
	del(ilst);
	*lst = 0;
}
