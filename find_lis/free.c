/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:47:18 by rigel             #+#    #+#             */
/*   Updated: 2022/03/22 12:37:05 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_list(t_list **lst)
{
	t_list	*begin_list;
	t_list	*temp;

	begin_list = *lst;
	while (begin_list)
	{
		temp = begin_list->next;
		free(begin_list);
		begin_list = temp;
	}
	*lst = 0;
}

void	free_uplst(t_uplist **ulst)
{
	t_uplist	*begin_list;

	begin_list = *ulst;
	free_list(&begin_list->lst);
	free(begin_list);
	*ulst = 0;
}
