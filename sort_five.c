/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 05:39:41 by rigel             #+#    #+#             */
/*   Updated: 2022/03/20 14:05:15 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three(t_stack *stack)
{
    t_elem *l;
    l = stack->a;
    if(l->lvl > l->next->lvl && l->next->lvl < l->next->next->lvl && l->lvl < l->next->next->lvl)
        op_sa(stack);
    else if(l->lvl > l->next->lvl && l->next->lvl > l->next->next->lvl && l->lvl > l->next->next->lvl)
    {
        op_sa(stack);
        op_rra(stack);
    }
    else if(l->lvl > l->next->lvl && l->next->lvl < l->next->next->lvl && l->lvl > l->next->next->lvl)
        op_ra(stack);
    else if(l->lvl < l->next->lvl && l->next->lvl > l->next->next->lvl && l->lvl < l->next->next->lvl)
    {
        op_sa(stack);
        op_ra(stack);
    }
    else if(l->lvl < l->next->lvl && l->next->lvl > l->next->next->lvl && l->lvl > l->next->next->lvl)
        op_rra(stack);
}

static void sort_four(t_stack *stack)
{
        op_pb(stack);
        sort_three(stack);
        if(check_bottom(stack->a,stack->b->lvl) < check_top(stack->a_end,stack->b->lvl))
            rotate_ra(stack);
        else
            rotate_rra(stack);
}

void    sort_five(t_stack *stack)
{
    if(stack->a_len == 3)
        sort_three(stack);
    else if (stack->a_len == 4)
        sort_four(stack);
    else
    {
        op_pb(stack);
        op_pb(stack);
        sort_three(stack);
        if(check_bottom(stack->a,stack->b->lvl) < check_top(stack->a_end,stack->b->lvl))
            rotate_ra(stack);
        else
            rotate_rra(stack);
        if(check_bottom(stack->a,stack->b->lvl) < check_top(stack->a_end,stack->b->lvl))
            rotate_ra(stack);
        else
            rotate_rra(stack);
    }
}
