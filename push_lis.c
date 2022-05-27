/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:03:22 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:54:29 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_lis(int lvl, t_list *lis)
{
	t_list	*lst;

	lst = lis;
	while (lst)
	{
		if (lst->content == lvl)
			return (TRUE);
		lst = lst->next;
	}
	return (FALSE);
}

void	push_lis(t_stack *stack, t_list *lis)
{
	int		lvl;
	int		i;
	t_elem	*lst;

	i = 0;
	lst = stack->a;
	while (lst)
	{
		if (is_lis(lst->lvl, lis))
		{
			lvl = lst->lvl;
			break ;
		}
		lst = lst->next;
	}
	while (i != 2)
	{
		if (stack->a->lvl == lvl)
			i++;
		while (!is_lis(stack->a->lvl, lis))
			ft_putstr(op_pb(stack));
		ft_putstr(op_ra(stack));
	}
}
