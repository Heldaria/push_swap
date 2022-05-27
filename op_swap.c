/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:11:28 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:54:16 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*op_sa(t_stack *stack)
{
	int	tmp;

	tmp = stack->a->val;
	stack->a->val = stack->a->next->val;
	stack->a->next->val = tmp;
	tmp = stack->a->lvl;
	stack->a->lvl = stack->a->next->lvl;
	stack->a->next->lvl = tmp;
	return ("sa\n");
}

char	*op_sb(t_stack *stack)
{
	int	tmp;

	tmp = stack->b->val;
	stack->b->val = stack->b->next->val;
	stack->b->next->val = tmp;
	tmp = stack->b->lvl;
	stack->b->lvl = stack->b->next->lvl;
	stack->b->next->lvl = tmp;
	return ("sb\n");
}

char	*op_ss(t_stack *stack)
{
	op_sa(stack);
	op_sb(stack);
	return ("ss\n");
}
