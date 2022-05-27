/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:58:55 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:55:43 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mv_tab(t_stack *stack, t_elem *lst_b, int *coord)
{
	if (lst_b->pos > (stack->b_len / 2))
		coord[1] = lst_b->pos - stack->b_len;
	else
		coord[1] = lst_b->pos;
	if (find_next_pos(stack->a, lst_b->lvl) == -1)
	{
		if (find_prev_pos(stack->a, lst_b->lvl) > stack->a_len)
			coord[0] = (find_prev_pos(stack->a, lst_b->lvl) - stack->a_len);
		else
			coord[0] = find_prev_pos(stack->a, lst_b->lvl);
	}
	else if (find_next_pos(stack->a, lst_b->lvl) > (stack->a_len / 2))
		coord[0] = find_next_pos(stack->a, lst_b->lvl) - stack->a_len;
	else if (find_next_pos(stack->a, lst_b->lvl) <= (stack->a_len / 2))
		coord[0] = find_next_pos(stack->a, lst_b->lvl);
}

int	mv_calcul(int *tab)
{
	if (tab[1] * tab[0] > 0)
		return (max(tab));
	else
		return (abs(tab[0]) + abs(tab[1]));
}

void	sort(t_stack *stack, t_list *lis)
{
	int			coord[2];
	int			tmp[2];
	int			min;
	t_elem		*lst_b;

	push_lis(stack, lis);
	while (stack->b)
	{
		lst_b = stack->b;
		mv_tab(stack, lst_b, coord);
		min = mv_calcul(coord);
		while (lst_b)
		{
			mv_tab(stack, lst_b, tmp);
			if (mv_calcul(tmp) < min)
			{
				min = mv_calcul(tmp);
				mv_tab(stack, lst_b, coord);
			}
			lst_b = lst_b->next;
		}
		exec_tab(coord[0], coord[1], stack);
	}
}

void	exec_tab(int mva, int mvb, t_stack *stack)
{
	int	a;
	int	b;

	a = mva;
	b = mvb;
	while (a != 0 || b != 0)
	{
		if ((a * b) > 0)
			same_sign(&a, &b, stack);
		else
			diff_sign(&a, &b, stack);
	}
	ft_putstr(op_pa(stack));
}
