/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:11:28 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:54:04 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*op_ra(t_stack *stack)
{
	t_elem	*temp;

	if (stack->a_len < 2)
		return (NULL);
	temp = stack->a->next;
	temp->prev = NULL;
	stack->a->next = NULL;
	stack->a_end->next = stack->a;
	stack->a = temp;
	stack->a_end->next->prev = stack->a_end;
	stack->a_end = stack->a_end->next;
	set_pos(stack);
	return ("ra\n");
}

char	*op_rb(t_stack *stack)
{
	t_elem	*temp;

	if (stack->b_len < 2)
		return (NULL);
	temp = stack->b->next;
	temp->prev = NULL;
	stack->b->next = NULL;
	stack->b_end->next = stack->b;
	stack->b = temp;
	stack->b_end->next->prev = stack->b_end;
	stack->b_end = stack->b_end->next;
	set_pos(stack);
	return ("rb\n");
}

char	*op_rr(t_stack *stack)
{
	op_ra(stack);
	op_rb(stack);
	return ("rr\n");
}
