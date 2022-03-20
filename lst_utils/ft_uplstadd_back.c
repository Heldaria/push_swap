/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uplstadd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:50:22 by rigel             #+#    #+#             */
/*   Updated: 2022/03/17 16:08:16 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_uplstadd_back(t_uplist *alst, t_uplist *new)
{
	t_uplist	*tmp;

	if (!alst || !new)
		return ;
	tmp = alst;
	if (alst == NULL)
	{
		alst = new;
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