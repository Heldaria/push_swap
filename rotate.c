/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:17:21 by rigel             #+#    #+#             */
/*   Updated: 2022/03/20 19:09:36 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next(t_elem *lst, int lvl)
{
	int	ret;

	ret = lst->lvl;
	while (lst)
	{
		if (lst->lvl < ret && lst->lvl > lvl)
			ret = lst->lvl;
		lst = lst->next;
	}
	if (ret < lvl)
		return (-1);
	return (ret);
}

int	find_prev(t_elem *lst, int lvl)
{
	int	ret;

	ret = lst->lvl;
	while (lst)
	{
		if (lst->lvl > ret && lst->lvl < lvl)
			ret = lst->lvl;
		lst = lst->next;
	}
	if (ret > lvl)
		return (-1);
	return (ret);
}

void	rotate_ra(t_stack *stack)
{
	int	uplvl;
	int	dlvl;

	uplvl = find_next(stack->a, stack->b->lvl);
	dlvl = find_prev(stack->a, stack->b->lvl);
	while (stack->a->lvl != uplvl && stack->a_end->lvl != dlvl)
		op_ra(stack);
	op_pa(stack);
}

void	rotate_rra(t_stack *stack)
{
	int	uplvl;
	int	dlvl;

	uplvl = find_next(stack->a, stack->b->lvl);
	dlvl = find_prev(stack->a, stack->b->lvl);
	while (stack->a->lvl != uplvl && stack->a_end->lvl != dlvl)
		op_rra(stack);
	op_pa(stack);
}
