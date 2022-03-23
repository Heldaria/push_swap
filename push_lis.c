/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:03:22 by rigel             #+#    #+#             */
/*   Updated: 2022/03/22 17:00:36 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min_pos(t_elem *stack_a)
{
	t_elem	*lst;

	lst = stack_a;
	while (lst)
	{
		if (lst->lvl == 0)
			return (lst->pos);
		lst = lst->next;
	}
	return (-1);
}

int	is_lis(int lvl, t_list *lis)
{
	t_list	*lst;

	lst = lis;
	while (lst)
	{
		if (lst->content == lvl)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}

void	push_lis(t_stack *stack, t_list *lis)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (get_min_pos(stack->a) > (stack->a_len / 2))
		k = 1;
	while (i != 2)
	{
		if (stack->a->lvl == 0)
			i++;
		if (i == 2)
			break ;
		while (!is_lis(stack->a->lvl, lis))
			op_pb(stack);
		if (k)
			op_rra(stack);
		else
			op_ra(stack);
	}
}
