/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:00:43 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:47:29 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_uplist	*find_lis(int *tab, int size)
{
	int			i;
	t_uplist	*ulst;

	ulst = ft_uplstnew(ft_lstnew(tab[0]));
	i = 1;
	while (i < size)
	{
		if (sup_ends(ulst, tab[i]))
			clone_sup(ulst, tab[i]);
		else
			between_ends(ulst, tab[i]);
		i++;
	}
	return (ulst);
}
