/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_ends.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 00:33:22 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:48:38 by llepiney         ###   ########.fr       */
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
