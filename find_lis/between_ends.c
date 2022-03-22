/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   between_ends.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:36:02 by rigel             #+#    #+#             */
/*   Updated: 2022/03/22 12:49:06 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static t_list	*find_nmax(t_uplist *ulst, int lvl)
{
	t_list		*ret;
	t_list		*tmp;
	t_uplist	*utmp;
	int			last;

	last = -1;
	utmp = ulst;
	while (utmp)
	{
		tmp = ft_lstlast(utmp->lst);
		if (tmp->content < lvl && tmp->content > last)
		{
			last = tmp->content;
			ret = utmp->lst;
		}
		utmp = utmp->next;
	}
	return (ret);
}

static void	discard(t_uplist *ulst, int size)
{
	t_uplist	*utmp;
	t_uplist	*utmpbis;

	utmp = ulst;
	while (utmp->next)
	{
		if (ft_lstsize(utmp->next->lst) == size)
		{
			utmpbis = utmp->next;
			utmp->next = utmp->next->next;
			free_uplst(&utmpbis);
			break ;
		}
		utmp = utmp->next;
	}
}

void	between_ends(t_uplist *ulst, int lvl)
{
	t_list		*clone;
	t_uplist	*unew;
	int			size;

	clone = duplicate(find_nmax(ulst, lvl));
	ft_lstadd_back(&clone, ft_lstnew(lvl));
	size = ft_lstsize(clone);
	discard(ulst, size);
	unew = ft_uplstnew(clone);
	ft_uplstadd_back(&ulst, unew);
}
