/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 03:36:15 by ayblin            #+#    #+#             */
/*   Updated: 2022/03/20 13:18:21 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_elem	*my_lstnew(int val)
{
	t_elem	*new;

	new = (t_elem *)malloc(sizeof(t_elem));
	if (!new)
		return (NULL);
	new->val = val;
	return (new);
}
t_elem	*my_lstnew2(int val, int lvl)
{
	t_elem	*new;

	new = (t_elem *)malloc(sizeof(t_elem));
	if (!new)
		return (NULL);
	new->val = val;
	new->lvl = lvl;
	return (new);
}

void	my_lst_print(t_elem *lst)
{
	while (lst)
	{
		printf("|%d,%d| ", lst->val,lst->lvl);
		lst = lst->next;
	}
	printf("\n");
}

void	my_lis_print(t_list *lst)
{
	while (lst)
	{
		printf("(%d) ", lst->content);
		lst = lst->next;
	}
	printf("\n");
}

void	print_stacks(t_stack *stack)
{
	    my_lst_print(stack->a);
        my_lst_print(stack->b);
		printf("\n");
}