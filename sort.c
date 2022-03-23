/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:58:55 by rigel             #+#    #+#             */
/*   Updated: 2022/03/23 02:02:27 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*mv_tab(t_stack *stack, t_elem *lst_b)
{
	int	*coord;

	coord = malloc(sizeof(int) * 2);
	if (lst_b->pos > (stack->b_len / 2))
		coord[1] = lst_b->pos - stack->b_len;
	else
		coord[1] = lst_b->pos;
	if (find_next_pos(stack->a, lst_b->lvl) == -1)
	{
		if (find_prev_pos(stack->a, lst_b->lvl) > stack->a_len)
			coord[0] = (find_prev_pos(stack->a, lst_b->lvl) - stack->a_len) + 1;
		else
			coord[0] = find_prev_pos(stack->a, lst_b->lvl) + 1;
	}
	else if (find_next_pos(stack->a, lst_b->lvl) > (stack->a_len / 2))
		coord[0] = find_next_pos(stack->a, lst_b->lvl) - stack->a_len;
	else if (find_next_pos(stack->a, lst_b->lvl) <= (stack->a_len / 2))
		coord[0] = find_next_pos(stack->a, lst_b->lvl);
	return (coord);
}

int	mv_calcul(int *tab)
{
	int	tmp;

	if (tab[1] * tab[0] > 0)
	{
		tmp = max(tab);
		free(tab);
		return (tmp);
	}
	else
	{
		tmp = abs(tab[0]) + abs(tab[1]);
		free(tab);
		return (tmp);
	}
}

void	sort(t_stack *stack, t_list *lis)
{
	t_elem		*lst_b;
	int			min;
	int			*mintab;

	push_lis(stack, lis);
	min = mv_calcul(mv_tab(stack, stack->b));
	mintab = mv_tab(stack, stack->b);
	 printf("%d%d",mintab[0],min);
	while (stack->b_len > 0)
	{
		lst_b = stack->b; 
		while (lst_b)
		{
			if (mv_calcul(mv_tab(stack, lst_b)) < min)
			{
				min = mv_calcul(mv_tab(stack, lst_b));
				free(mintab);
				mintab = mv_tab(stack, lst_b);
			}
			lst_b = lst_b->next;
		}
		exec_tab(mintab, stack);
	}
}

void	exec_tab(int *mintab, t_stack *stack)
{
	while (mintab[0] != 0 || mintab[1] != 0)
	{
		if ((mintab[0] * mintab[1]) > 0)
			same_sign(mintab, stack);
		else
			dif_sign(mintab, stack);
	}
	op_pb(stack);
}
