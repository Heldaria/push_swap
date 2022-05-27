/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 06:54:20 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:53:00 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort(int *tab, t_stack *stack)
{
	int		i;
	t_elem	*begin;

	i = -1;
	while (++i < stack->a_len)
	{
		begin = stack->a;
		while (begin)
		{
			if (begin->val == tab[i])
				begin->lvl = i;
			begin = begin->next;
		}
	}
	free(tab);
}

int	*tab_create(char **argv, int len)
{
	int	*tab;
	int	i;

	i = 0;
	tab = malloc(sizeof(int) * len);
	while (i < len)
	{
		tab[i] = ft_atoi(argv[i]);
		i++;
	}
	return (tab);
}

void	sort_int_tab(int *tab, unsigned int size)
{
	unsigned int	a;
	int				tmp;

	a = 1;
	if (size != 0)
	{
		while (a <= size)
		{
			if (tab[a] < tab[a - 1])
			{
				tmp = tab[a];
				tab[a] = tab[a - 1];
				tab[a - 1] = tmp;
				a = 0;
			}
			++a;
		}
	}
}

int	*listab_create(t_elem *stack_a, int len)
{
	t_elem	*tmp;
	int		*ret;
	int		i;

	ret = malloc(sizeof(int) * len);
	if (!ret)
		return (0);
	tmp = stack_a;
	i = 0;
	while (tmp->lvl != 0)
		tmp = tmp->next;
	while (tmp)
	{
		ret[i] = tmp->lvl;
		i++;
		tmp = tmp->next;
	}
	tmp = stack_a;
	while (tmp->lvl != 0)
	{
		ret[i] = tmp->lvl;
		i++;
		tmp = tmp->next;
	}
	return (ret);
}
