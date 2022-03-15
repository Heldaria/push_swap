/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uplstlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:24:56 by llepiney          #+#    #+#             */
/*   Updated: 2022/03/15 21:25:32 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*ft_uplstlast(t_uplist *uplst)
{
	while (uplst)
	{
		if (uplst->next == NULL)
			return (uplst);
		uplst = uplst->next;
	}
	return (uplst);
}