/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <llepiney@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:45:40 by llepiney          #+#    #+#             */
/*   Updated: 2022/04/08 22:52:01 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	exec_op(t_stack *stack, char *str)
{
	if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
		op_rra(stack);
	else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
		op_rrb(stack);
	else if (ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
		op_rrr(stack);
	else if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
		op_sa(stack);
	else if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
		op_sb(stack);
	else if (ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
		op_ss(stack);
	else if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
		op_ra(stack);
	else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
		op_rb(stack);
	else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
		op_rr(stack);
	else if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
		op_pa(stack);
	else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
		op_pb(stack);
	else
		return (0);
	return (1);
}

static int	is_sorted(t_elem *lst)
{
	while (lst)
	{
		if (lst->next && lst->next->val < lst->val)
			return (0);
		lst = lst->next;
	}
	return (1);
}

static int	check_ok(t_stack *stack)
{
	char	*str;

	while (1)
	{
		str = get_next_line(1, 0);
		if (!str)
		{
			if (is_sorted(stack->a) && !stack->b)
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
			free(str);
			return (0);
		}
		if (!exec_op(stack, str))
		{
			free(str);
			str = get_next_line(2, 0);
			ft_putstr("Error\n");
			free(str);
			return (0);
		}
		free(str);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack		*stack;
	char		**arg;

	if (ac == 1)
		return (1);
	if (ac == 2)
		arg = ft_split(av[1], ' ');
	else
		arg = av + 1;
	if (error_check(arg) == 0)
	{
		if (ac == 2)
			free_tab(arg);
		return (1);
	}
	stack = init_stack(arg);
	check_ok(stack);
	free_stack(stack);
}
