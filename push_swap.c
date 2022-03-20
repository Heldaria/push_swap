/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 03:36:11 by ayblin            #+#    #+#             */
/*   Updated: 2022/03/20 19:27:10 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	/*
	(void)ac;
	t_stack	*stack;
	int		*tab;
	
	stack = init_stack(++av);
	tab = tab_create(av, stack->a_len);
	sort_int_tab(tab, stack->a_len - 1);
	pre_sort(tab,stack);
	free(tab);
	if (stack->a_len >= 3 && stack->a_len <= 5)                
		sort_five(stack);
	print_stacks(stack);*/
	t_list	*pet;
	t_list	*lst;

	(void)ac;
	(void)av;
	lst = ft_lstnew(1);
	ft_lstadd_back(&(lst), ft_lstnew(2));
	ft_lstadd_back(&(lst), ft_lstnew(3));
	ft_lstadd_back(&(lst), ft_lstnew(4));
	ft_lstadd_back(&(lst), ft_lstnew(5));
	ft_lstadd_back(&(lst), ft_lstnew(6));
	my_lis_print(lst);
	pet = duplicate(lst);
	my_lis_print(pet);
	return (0);
}
