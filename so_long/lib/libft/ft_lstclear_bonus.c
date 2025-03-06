/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:38:05 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/03 11:13:36 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ilst;

	if (!lst)
		return ;
	ilst = *lst;
	if (!ilst)
		return ;
	if (ilst->content != 0)
		del(ilst->content);
	if (ilst->next)
		ft_lstclear(&ilst->next, del);
	free(ilst);
	*lst = 0;
}
