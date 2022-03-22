/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:24:55 by rigel             #+#    #+#             */
/*   Updated: 2022/03/21 12:50:01 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    op_sa(t_stack *stack)
{
	int tmp;

	tmp = stack->a->val;
	stack->a->val = stack->a->next->val;
	stack->a->next->val = tmp;
	tmp = stack->a->lvl;
	stack->a->lvl = stack->a->next->lvl;
	stack->a->next->lvl = tmp;
	write(1,"sa\n",3);
}

void    op_sb(t_stack *stack)
{
	int tmp;

	tmp = stack->b->val;
	stack->b->val = stack->b->next->val;
	stack->b->next->val = tmp;
	tmp = stack->b->lvl;
	stack->b->lvl = stack->b->next->lvl;
	stack->b->next->lvl = tmp;
	write(1,"sb\n",3);
}

void    op_ss(t_stack *stack)
{
	op_sa(stack);
	op_sb(stack);
	write(1,"ss\n",3);
}

void    op_ra(t_stack *stack)
{
	t_elem	*temp;

	temp = stack->a->next;
	temp->prev = NULL;
	stack->a->next = NULL;
	stack->a_end->next = stack->a;
	stack->a = temp;
	stack->a_end->next->prev = stack->a_end;
	stack->a_end = stack->a_end->next;
	write(1,"ra\n",3);
	set_pos(stack);
}

void    op_rb(t_stack *stack)
{
	t_elem	*temp;

	temp = stack->b->next;
	temp->prev = NULL;
	stack->b->next = NULL;
	stack->b_end->next = stack->b;
	stack->b = temp;
	stack->b_end->next->prev = stack->b_end;
	stack->b_end = stack->b_end->next;
	write(1,"rb\n",3);
	set_pos(stack);
}

void    op_rs(t_stack *stack)
{
	op_ra(stack);
	op_rb(stack);
}

void    op_rra(t_stack *stack)
{
	stack->a->prev = stack->a_end;
	stack->a_end->next = stack->a;
	stack->a_end->prev->next = NULL;
	stack->a_end->prev = NULL;
	stack->a = stack->a_end;
	stack->a_end = my_lstlast(stack->a);
	write(1,"rra\n",4);
	set_pos(stack);
}

void    op_rrb(t_stack *stack)
{
	stack->b->prev = stack->a_end;
	stack->b_end->next = stack->a;
	stack->b_end->prev->next = NULL;
	stack->b_end->prev = NULL;
	stack->b = stack->a_end;
	stack->b_end = my_lstlast(stack->a);
	write(1,"rrb\n",4);
	set_pos(stack);
}


void    op_rrs(t_stack *stack)
{
	op_rra(stack);
	op_rrb(stack);
}

void    op_pb(t_stack *stack)
{
	t_elem  *tmp;
	t_elem  *push;

	push = my_lstnew(stack->a->val);
	push->next = stack->b;
	push->prev = NULL;
	push->lvl = stack->a->lvl;
	stack->b = push;
	tmp = stack->a;
	stack->a = stack->a->next;
	free(tmp);
	write(1,"pb\n",3);
	stack->b_len++;
	stack->a_len--;
	set_pos(stack);
}

void    op_pa(t_stack *stack)
{
	t_elem  *tmp;
	t_elem	*push;

	push = my_lstnew(stack->b->val);
	push->next = stack->a;
	push->prev = NULL;
	push->lvl = stack->b->lvl;
	stack->a = push;
	tmp = stack->b;
	stack->b = stack->b->next;
	free(tmp);
	write(1, "pa\n",3);
	stack->a_len++;
	stack->b_len--;
	set_pos(stack);
}

void    set_pos(t_stack *stack)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = stack->a;
	while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
	i = 0;
	tmp = stack->b;
		while (tmp)
	{
		tmp->pos = i;
		i++;
		tmp = tmp->next;
	}
}