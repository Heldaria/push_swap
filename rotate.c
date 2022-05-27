/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:17:21 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:55:10 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ra(t_stack *stack)
{
	int	uplvl;
	int	dlvl;

	uplvl = find_next(stack->a, stack->b->lvl);
	dlvl = find_prev(stack->a, stack->b->lvl);
	while (stack->a->lvl != uplvl && stack->a_end->lvl != dlvl)
		ft_putstr(op_ra(stack));
	ft_putstr(op_pa(stack));
}

void	rotate_rra(t_stack *stack)
{
	int	uplvl;
	int	dlvl;

	uplvl = find_next(stack->a, stack->b->lvl);
	dlvl = find_prev(stack->a, stack->b->lvl);
	while (stack->a->lvl != uplvl && stack->a_end->lvl != dlvl)
		ft_putstr(op_rra(stack));
	ft_putstr(op_pa(stack));
}
