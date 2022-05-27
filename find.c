/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:44:41 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:52:05 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_next(t_elem *lst, int lvl)
{
	int	ret;

	ret = lst->lvl;
	while (lst)
	{
		if (lst->lvl <= ret && lst->lvl > lvl)
			ret = lst->lvl;
		lst = lst->next;
	}
	if (ret < lvl)
		return (-1);
	return (ret);
}

int	find_prev(t_elem *lst, int lvl)
{
	int	ret;

	ret = lst->lvl;
	while (lst)
	{
		if (lst->lvl >= ret && lst->lvl < lvl)
			ret = lst->lvl;
		lst = lst->next;
	}
	if (ret > lvl)
		return (-1);
	return (ret);
}

int	find_next_pos(t_elem *lst, int lvl)
{
	int	ret;
	int	pos;

	ret = -1;
	pos = 0;
	while (lst)
	{
		if (ret == -1 && lst->lvl > lvl)
		{
			ret = lst->lvl;
			pos = lst->pos;
		}
		if (lst->lvl < ret && lst->lvl > lvl)
		{
			ret = lst->lvl;
			pos = lst->pos;
		}
		lst = lst->next;
	}
	if (ret == -1)
		return (-1);
	return (pos);
}

int	find_prev_pos(t_elem *lst, int lvl)
{
	int	ret;
	int	pos;

	ret = -1;
	pos = 0;
	while (lst)
	{
		if (ret == -1 && lst->lvl < lvl)
			ret = lst->lvl;
		if (lst->lvl < ret && lst->lvl < lvl)
		{
			ret = lst->lvl;
			pos = lst->pos;
		}
		lst = lst->next;
	}
	if (ret == -1)
		return (-1);
	return (pos);
}
