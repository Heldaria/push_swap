/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clone_sup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:54:43 by rigel             #+#    #+#             */
/*   Updated: 2022/03/21 13:08:37 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*longest_list(t_uplist *ulst)
{
	int		tmp;
	t_list	*ret;

	tmp = 0;
	while (ulst)
	{
		if (ft_lstsize(ulst->lst) > tmp)
		{
			tmp = ft_lstsize(ulst->lst);
			ret = ulst->lst;
		}
		ulst = ulst->next;
	}
	return (ret);
}

void	clone_sup(t_uplist *ulst, int nb)
{
	t_list		*new;
	t_list		*longest;
	t_uplist	*unew;

	longest = duplicate(longest_list(ulst));
	new = ft_lstnew(nb);
	ft_lstadd_back(&longest, new);
	unew = ft_uplstnew(longest);
	ft_uplstadd_back(&ulst, unew);
}
