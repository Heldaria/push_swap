/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 08:16:14 by llepiney          #+#    #+#             */
/*   Updated: 2022/03/14 11:37:26 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len(int *array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
		return (i);
}

void	fill_ends(int *ends, int **all_arrays)//pour remplir tab d'ends a chaque fois
{
	int	i;
	int	line_length;

	i = 0;
	while (ends[i])
	{
		line_length = ft_len(all_arrays[i]);
		if (all_arrays[i] != 0) //si la ligne pas discard
			ends[i] = all_arrays[i][line_length - 1]; //remplir index i par end
		i++;
	}
}

int	comp(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (2);
	return (0);
}

t_list	*longest_lst(t_uplist *all)
{
	t_uplist	*tmpup;
	t_list		*longest_lst;

	longest_lst = all->lst;
	while (tmpup->lst)
	{
		if (longest_lst < ft_lstsize(tmpup->lst))
			longest_lst = tmpup->lst;
		tmpup->next;
	}
	return (longest_lst);
}

int	case_biggest(int num, t_list *ends, t_uplist *all)
{
	t_list	*tmp;

	tmp = ends;
	while (tmp->content)
	{
		if (num < tmp->content)
			return (0);
		tmp = tmp->next; //parcourt, si num pas plus grand, sort
	}
	ft_lstadd_back(longest(all), ft_lstnew(num)); //ajoute elem a liste la plus longue avec num
	return (0);
}

int	*find_lis(int *stack)
{
	t_list		*ends;
	t_uplist	*all;
	int			i;

	ends = malloc(sizeof(int) * ft_len(stack));
	if (!ends)
		return (0);
	all = ft_uplstnew(ft_lstnew(stack[0])); // creer liste de listes + remplit avec premier nbr de stack
	ends = ft_lstnew(stack[0]); //ends initial
	i = 1;
	while (stack[i])
	{
		case_biggest(stack[i], ends, all);
		fill_ends(ends); //update tableau d'ends
	}
}