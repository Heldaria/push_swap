/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:20:51 by llepiney          #+#    #+#             */
/*   Updated: 2022/03/20 19:25:26 by rigel            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef struct s_elem
{
	int				val;
	int				lvl;
	int				pos;
	struct s_elem	*next;
	struct s_elem	*prev;
}	t_elem;

typedef struct s_stack
{
	struct s_elem	*a;
	struct s_elem	*a_end;
	int				a_len;

	struct s_elem	*b;
	struct s_elem	*b_end;
	int				b_len;	
}	t_stack;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}			t_list;

typedef struct s_uplist
{
	struct s_list	*lst;
	struct s_uplist	*next;
}			t_uplist;

int			ft_atoi(const char *nptr);
int			*tab_create(char **argv, int len);
void		sort_int_tab(int *tab, unsigned int size);
void		pre_sort(int *tab, t_stack *stack);
t_elem		*my_lstnew(int val);
void		my_lst_print(t_elem *lst);
void		my_lis_print(t_list *lst);
void		print_stacks(t_stack *stack);

t_stack		*init_stack(char **val);
void		op_sa(t_stack *stack);
void		op_sb(t_stack *stack);
void		op_ss(t_stack *stack);
void		op_ra(t_stack *stack);
void		op_rb(t_stack *stack);
void		op_rs(t_stack *stack);
void		op_rra(t_stack *stack);
void		op_rrb(t_stack *stack);
void		op_rrs(t_stack *stack);
void		op_pa(t_stack *stack);
void		op_pb(t_stack *stack);
void		set_pos(t_stack *stack);
void		rotate_ra(t_stack *stack);
void		rotate_rra(t_stack *stack);
int			find_prev(t_elem *lst, int lvl);
int			find_next(t_elem *lst, int lvl);
void		sort_three(t_stack *stack);
void		sort_five(t_stack *stack);
int			check_bottom(t_elem *start, int lvl);
int			check_top(t_elem *start, int lvl);

/*void		ft_lstclear(t_list **lst);
t_list		*fill_ends(t_uplist *all);
int			first_nmax(int num, t_list *ends);
t_list		*find_lis(int *stack, int size); */

t_list		*ft_lstnew(int content);
t_elem		*my_lstnew2(int val, int lvl);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_elem		*my_lstlast(t_elem *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_uplstadd_back(t_uplist *alst, t_uplist *new);
t_uplist	*ft_uplstlast(t_uplist *uplst);
t_uplist	*ft_uplstnew(t_list *lst);
t_list		*duplicate(t_list *lst);

#endif