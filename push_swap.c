/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 03:36:11 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/11 16:41:00 by llepiney         ###   ########.fr       */
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
			ft_putstr(op_rra(stack));
	}
	else
	{
		while (stack->a->lvl != 0)
			ft_putstr(op_ra(stack));
	}
}

int	main(int ac, char **av)
{
	t_stack		*stack;
	int			*tab;
	char		**arg;

	if (ac == 1)
		return (1);
	if (ac == 2)
		arg = ft_split(av[1], ' ');
	else
		arg = av + 1;
	if (error_check(arg) < 1)
	{
		if (ac == 2)
			free_tab(arg);
		return (0);
	}
	stack = init_stack(arg);
	set_pos(stack);
	tab = tab_create(arg, stack->a_len);
	if (ac == 2)
		free_tab(arg);
	sort_int_tab(tab, stack->a_len - 1);
	pre_sort(tab, stack);
	push_swap(stack);
	return (0);
}

void	push_swap(t_stack *stack)
{
	int			*tab;
	t_uplist	*lis;

	if (stack->a_len >= 2 && stack->a_len <= 5)
		sort_five(stack);
	else
	{	
		tab = listab_create(stack->a, stack->a_len);
		lis = find_lis(tab, stack->a_len);
		free(tab);
		sort(stack, longest_list(lis));
		free_uplst(&lis);
	}
	min_first(stack);
	free_stack(stack);
}
