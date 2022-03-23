/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigel <rigel@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 09:20:51 by llepiney          #+#    #+#             */
/*   Updated: 2022/03/23 01:32:02 by rigel            ###   ########.fr       */
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
int			abs(int nb);
int			*tab_create(char **argv, int len);
void		sort_int_tab(int *tab, unsigned int size);
void		pre_sort(int *tab, t_stack *stack);

/*       PRINT       */
void		my_lst_print(t_elem *lst);
void		my_lis_print(t_list *lst);
void		print_stacks(t_stack *stack);
void		print_ulst(t_uplist *ulst);
void		print_mv_tab(t_stack *stack);
/*       OPERATION     */
t_stack		*init_stack(char **val);
void		min_first(t_stack	*stack);
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
int			get_min_pos(t_elem *stack_a);
int			is_lis(int lvl, t_list *lis);
int			find_next_pos(t_elem *lst, int lvl);
int			find_prev_pos(t_elem *lst, int lvl);
void		push_lis(t_stack *stack, t_list *lis);
int			abs(int nb);
int			min(int *tab);
int			max(int *tab);
void		sort(t_stack *stack, t_list *lis);
int			*mv_tab(t_stack *stack, t_elem *lst_b);
int			mv_calcul(int *tab);
void		same_sign(int *mintab, t_stack *stack);
void		dif_sign(int *mintab, t_stack *stack);
void		exec_tab(int *mintab, t_stack *stack);
/*      FIND LIS      */
t_uplist	*find_lis(int *tab, int size);
t_list		*longest_list(t_uplist *ulst);
void		clone_sup(t_uplist *ulst, int nb);
int			sup_ends(t_uplist *ulst, int num);
t_list		*duplicate(t_list *lst);
int			*tab_create2(t_elem *stack, int len);
void		between_ends(t_uplist *ulst, int lvl);
/*      LST UTILS     */
t_list		*ft_lstnew(int content);
t_elem		*my_lstnew2(int val, int lvl);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
t_elem		*my_lstlast(t_elem *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_uplstadd_back(t_uplist **alst, t_uplist *new);
t_uplist	*ft_uplstlast(t_uplist *uplst);
t_uplist	*ft_uplstnew(t_list *lst);
t_elem		*my_lstnew(int val);

void		free_list(t_list **lst);
void		free_uplst(t_uplist **ulst);

#endif