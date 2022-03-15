/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 08:16:14 by llepiney          #+#    #+#             */
/*   Updated: 2022/03/15 22:13:45 by llepiney         ###   ########.fr       */
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

void	fill_ends(int *ends, int **all_arrays) //pour remplir tab d'ends a chaque fois
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
	return (1);
}

int	first_nmax(int num, t_list *ends)
{
	t_list	*tmp;

	tmp = ends;
	while (tmp->content)
	{
		if (tmp->content < num)
			return(tmp->content);
		tmp->next;
	}
	return (0);
}

int	*find_lis(int *stack)
{
	t_list		*ends;
	t_uplist	*all;
	t_uplist	*begin;
	t_uplist	*tmp;
	int			i;
	int			nmax;

	ends = malloc(sizeof(int) * ft_len(stack));
	if (!ends)
		return (0);
	all = ft_uplstnew(ft_lstnew(stack[0])); // creer upliste de listes + remplit lst avec premier nbr de stack
	ends = ft_lstnew(stack[0]); //ends initial
	i = 1;
	while (stack[i])
	{
		if (case_biggest(stack[i], ends, all) == 0)
		{
			nmax = first_nmax(stack[i]);
			while (ends->content)
			{
				if (ends->content < stack[i] && ends->content > nmax)// si end d'une liste < num actuel && > num max inf
					nmax = ends->content;
				ends->next;
			}//nmax est le max inf a stack[i]
			begin = *all; // pas sure
			while (begin->lst) //boucle pour atteindre lst a extend puis extend
			{
				if (ft_lstlast(begin->lst) == nmax)
				{
					ft_lstadd_back(*begin->lst, ft_lstnew(nmax));
					break ;
				}
				begin->next;
			}
			all = *begin; // pas sure
			begin = *all;
			while (begin->next->lst)// pour discard les lst m size que la new jusqu'a avant derniere
			{
				if (ft_lstsize(begin->lst) == ft_lstsize(ft_uplstlast(begin)))
				{
					tmp = begin->next;
					free(begin->lst->content);
					free(begin->lst);
					begin = tmp;
				}
			}
			all = begin; //pas sure
		}
		fill_ends(ends); //update liste d'ends
	}
	return (longest_lst(all));
}