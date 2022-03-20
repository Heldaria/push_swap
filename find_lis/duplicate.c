/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:24:16 by rigel             #+#    #+#             */
/*   Updated: 2022/03/20 19:24:54 by rigel            ###   ########.fr       */
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
	while (to_clone && res)
	{
		ft_lstadd_back(&res, ft_lstnew(lst->content));
		res = res->next;
		to_clone = to_clone->next;
	}
	return (res);
}