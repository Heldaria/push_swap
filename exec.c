/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 01:11:28 by rigel             #+#    #+#             */
/*   Updated: 2022/03/23 02:02:21 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	same_sign(int *mintab, t_stack *stack)
{
	if (mintab[0] < 0)
	{
		op_rrs(stack);
		mintab[0] = mintab[0]+ 1;
		mintab[1] += 1;
	}
	else
	{
		op_rs(stack);
		mintab[0] -= 1;
		mintab[1] -= 1;
	}
}

void	dif_sign(int *mintab, t_stack *stack)
{
	if (mintab[0] < 0)
	{
		op_rra(stack);
		mintab[0] += 1;
	}
	if (mintab[0] > 0)
	{
		op_ra(stack);
		mintab[0] -= 1;
	}
	if (mintab[1] < 0)
	{
		op_rrb(stack);
		mintab[1] += 1;
	}
	if (mintab[1] > 0)
	{
		op_rb(stack);
		mintab[1] -= 1;
	}
}
