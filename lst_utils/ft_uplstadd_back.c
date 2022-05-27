/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uplstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:50:22 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:50:37 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_uplstadd_back(t_uplist **alst, t_uplist *new)
{
	t_uplist	*tmp;

	if (alst)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			tmp = ft_uplstlast(*alst);
			tmp->next = new;
		}
	}
}
