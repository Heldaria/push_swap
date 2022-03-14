/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:50:54 by llepiney          #+#    #+#             */
/*   Updated: 2022/03/14 10:15:39 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	if (!alst || !new)
		return ;
	tmp = *alst;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (tmp)
	{
		if (tmp->next == NULL)
		{
			tmp->next = new;
			break ;
		}
		tmp = tmp->next;
	}
}
