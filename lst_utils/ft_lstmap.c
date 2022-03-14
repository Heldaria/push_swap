/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:09:38 by llepiney          #+#    #+#             */
/*   Updated: 2022/03/14 10:16:11 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*begin_list;
	t_list	*new;

	if (!f || !del)
		return (0);
	begin_list = NULL;
	while (lst)
	{
		new = ft_lstnew((f)(lst->content));
		if (!new)
			ft_lstclear(&begin_list, del);
		ft_lstadd_back(&begin_list, new);
		lst = lst->next;
	}
	return (begin_list);
}
