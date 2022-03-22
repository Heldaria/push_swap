/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 03:36:11 by ayblin            #+#    #+#             */
/*   Updated: 2022/03/21 14:24:10 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_first(t_stack	*stack)
{
	t_elem	*tmp;

	tmp = stack->a;
	while (tmp && tmp->lvl != 0)
		tmp = tmp->next;
	if (tmp->pos > (stack->a_len / 2))
	{
		while (stack->a->lvl != 0)
			op_rra(stack);
	}
	else
	{
		while (stack->a->lvl != 0)
			op_ra(stack);
	}
}

int	*tab_create2(t_elem *stack, int len)
{
	t_elem	*tmp;
	int		*ret;
	int		i;

	ret = malloc(sizeof(int) * len);
	if (!ret)
		return (0);
	tmp = stack;
	i = 0;
	while (i < len)
	{
		ret[i] = tmp->lvl;
		i++;
		tmp = tmp->next;
	}
	return (ret);
}

int	main(int ac, char **av)
{
	t_stack		*stack;
	int			*tab;
	t_uplist	*lis;

	(void)ac;
	stack = init_stack(++av);
	print_stacks(stack);
	tab = tab_create(av, stack->a_len);
	sort_int_tab(tab, stack->a_len - 1);
	pre_sort(tab, stack);
	free(tab);
//	if (stack->a_len >= 3 && stack->a_len <= 5)
//		sort_five(stack);
	min_first(stack);
	tab = tab_create2(stack->a, stack->a_len);
	lis = find_lis(tab, stack->a_len);
	(void)lis;
	print_stacks(stack);
	return (0);
}
