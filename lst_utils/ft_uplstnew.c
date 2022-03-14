/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uplstnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:48:50 by llepiney          #+#    #+#             */
/*   Updated: 2022/03/14 10:50:18 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_uplist	*ft_uplstnew(t_list *lst)
{
	t_uplist	*new;

	new = (t_uplist *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->lst = lst;
	new->next = NULL;
	return (new);
}
