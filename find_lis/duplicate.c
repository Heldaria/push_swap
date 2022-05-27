/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:24:16 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:46:50 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*duplicate(t_list *lst)
{
	t_list	*to_clone;
	t_list	*res;

	to_clone = lst;
	res = ft_lstnew(lst->content);
	to_clone = to_clone->next;
	while (to_clone)
	{
		ft_lstadd_back(&res, ft_lstnew(to_clone->content));
		to_clone = to_clone->next;
	}
	return (res);
}
