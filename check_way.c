/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:50:20 by rigel             #+#    #+#             */
/*   Updated: 2022/03/20 19:07:10 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_bottom(t_elem *start, int lvl)
{
	t_elem	*tmp;
	int		i;

	tmp = start;
	i = 0;
	while (tmp && lvl != (tmp->lvl + 1))
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	check_top(t_elem *start, int lvl)
{
	t_elem	*tmp;
	int		i;

	tmp = start;
	i = 0;
	while (tmp && lvl != (tmp->lvl + 1))
	{
		i++;
		tmp = tmp->prev;
	}
	return (i);
}
