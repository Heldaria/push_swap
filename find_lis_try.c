/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 08:16:14 by llepiney          #+#    #+#             */
/*   Updated: 2022/03/14 10:01:01 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_len(int *array) //pour avoir logueur d'un tab d'int
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	*create_array(int num)//pour creer un array de 1 nombre
{
	int	*array;

	array = malloc(sizeof(int));
	if (!array)
		return (0);
	array[0] = num;
	return (array);
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

void	remove_all(int **all_arrays) //pour suppr le tab des listes temporaires
{
	int	i;

	i = 0;
	while (all_arrays[i])
	{
		free(all_arrays[i]);
		i++;
	}
	free(all_arrays);
}

int	*find_lis(int *stack)
{
	int	*ends;
	int	**all_arrays;
	int	i;

	ends = malloc(sizeof(int) * ft_len(stack));
	if (!ends)
		return (0);
	all_arrays = malloc(sizeof(int *) * ft_len(stack));
	if (!all_arrays)
		return (0);
	all_arrays[0] = create_array(stack[0]);
	i = 1;
	while (stack[i])
	{
		fill_ends(ends); //update tableau d'ends
	}
}
