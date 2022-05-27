/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:47:18 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:52:15 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	free_uplst_node(t_uplist **ulst)
{
	t_uplist	*begin_list;

	begin_list = *ulst;
	free_list(&begin_list->lst);
	free(begin_list);
	*ulst = 0;
}

void	free_uplst(t_uplist **ulst)
{
	t_uplist	*begin_list;
	t_uplist	*temp;

	begin_list = *ulst;
	while (begin_list)
	{
		temp = begin_list->next;
		free_uplst_node(&begin_list);
		begin_list = temp;
	}
	*ulst = 0;
}

void	free_stack(t_stack *stack)
{
	t_elem	*lst;
	t_elem	*tmp;

	lst = stack->a;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	lst = stack->b;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
	free(stack);
}
