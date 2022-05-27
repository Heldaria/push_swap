/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:58:32 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 17:56:03 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *nptr)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] > 8 && nptr[i] < 14))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}

int	abs(int nb)
{
	if (nb < 0)
		nb *= -1;
	return (nb);
}

int	min(int *tab)
{
	if (abs(tab[0]) < abs(tab[1]))
		return (abs(tab[0]));
	return (abs(tab[1]));
}

int	max(int *tab)
{
	if (abs(tab[0]) > abs(tab[1]))
		return (abs(tab[0]));
	return (abs(tab[1]));
}
