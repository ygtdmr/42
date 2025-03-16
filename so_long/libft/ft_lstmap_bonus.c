/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yidemir <yidemir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:18:44 by yidemir           #+#    #+#             */
/*   Updated: 2024/11/03 11:26:33 by yidemir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*nnode;
	void	*ncontent;

	nlst = 0;
	while (lst)
	{
		ncontent = f(lst->content);
		nnode = ft_lstnew(ncontent);
		if (!nnode)
		{
			del(ncontent);
			ft_lstclear(&nlst, del);
			return (0);
		}
		ft_lstadd_back(&nlst, nnode);
		lst = lst->next;
	}
	return (nlst);
}
