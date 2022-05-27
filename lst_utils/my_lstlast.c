/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 04:50:07 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:51:18 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_elem	*my_lstlast(t_elem *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}
