/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_ends.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:33:22 by rigel             #+#    #+#             */
/*   Updated: 2022/03/21 14:14:50 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sup_ends(t_uplist *ulst, int lvl)
{
	t_uplist	*utmp;
	t_list		*tmp;

	utmp = ulst;
	while (utmp)
	{
		tmp = ft_lstlast(utmp->lst);
		if (tmp->content > lvl)
			return (FALSE);
		utmp = utmp->next;
	}
	return (TRUE);
}
