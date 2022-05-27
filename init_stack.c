/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 03:44:44 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:52:46 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack2(t_stack *stack, int i)
{
	stack->a_end->next = NULL ;
	stack->a_len = i;
	stack->b = NULL;
	stack->b_len = 0;
}

t_stack	*init_stack(char **val)
{
	t_stack	*stack;
	t_elem	*elem;
	t_elem	*tmp;
	int		i;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	tmp = NULL;
	i = -1;
	while (val[++i])
	{
		elem = my_lstnew(ft_atoi(val[i]));
		if (!elem)
			return (NULL);
		if (!tmp)
			stack->a = elem;
		else
			tmp->next = elem;
		elem->prev = tmp;
		tmp = elem;
	}
	stack ->a_end = elem;
	init_stack2(stack, i);
	return (stack);
}
