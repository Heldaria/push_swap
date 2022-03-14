/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:01:02 by llepiney          #+#    #+#             */
/*   Updated: 2022/03/14 10:13:47 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*begin_list;
	t_list	*temp;

	begin_list = *lst;
	while (begin_list)
	{
		temp = begin_list->next;
		ft_lstdelone(begin_list, del);
		begin_list = temp;
	}
	*lst = 0;
}
