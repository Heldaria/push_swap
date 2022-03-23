/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 03:44:44 by ayblin            #+#    #+#             */
/*   Updated: 2022/03/22 13:09:57 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	stack->a_len = i;
	stack->b = NULL;
	set_pos(stack);
	return (stack);
}

