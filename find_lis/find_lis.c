/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:00:43 by rigel             #+#    #+#             */
/*   Updated: 2022/03/20 19:06:16 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_uplist	*find_lis(int *tab, int size)
{
	int			i;
	t_list		*ends;
	t_uplist	*ulst;

	ulst = ft_uplstnew(ft_lstnew(tab[0]));
	ends = ft_lstnew(tab[0]);
	i = 1;
	while (i++ < size)
	{
		if (sup_ends() == FALSE)
			between_ends();
		fill_ends();
	}
	free_lst(ends);
	return (ulst);
}

//oublie pas de clear ulst