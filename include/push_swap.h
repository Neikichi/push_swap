/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:11:57 by vlow              #+#    #+#             */
/*   Updated: 2024/12/29 20:13:18 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_op
{
	char	*buf_prv;
	char	*buf_cur;
}	t_op;

typedef struct s_stacks
{
	struct s_list	*a;
	struct s_list	*b;
	struct s_list	*ds;
	t_list			*ea;
	t_list			*eb;
	int				size;
	struct s_op		op;
}	t_stacks;

//push swap
void	ps_init(t_stacks *stacks);
void	ps_simple_a(t_stacks *stacks);
void	ps_simple_b(t_stacks *stacks);
void	ps_simple_ex(t_stacks *stacks);
void	ps_simple_3a(t_stacks *stacks);
void	ps_simple_3b(t_stacks *stacks);
void	ps_simple_2a(t_stacks *stacks);
void	ps_simple_2b(t_stacks *stacks);
void	ps_simple(t_stacks *stacks, int z);
void	is_init(t_stacks *stacks);
void	qs_init(t_stacks *stacks);

//push swap utils
void	init_stack(t_stacks *stacks);
void	ps_sa(t_stacks *stacks);
void	ps_sb(t_stacks *stacks);
void	ps_ss(t_stacks *stacks);
void	ps_pa(t_stacks *stacks);
void	ps_pb(t_stacks *stacks);
void	ps_ra(t_stacks *stacks);
void	ps_rb(t_stacks *stacks);
void	ps_rr(t_stacks *stacks);
void	ps_rra(t_stacks *stacks);
void	ps_rrb(t_stacks *stacks);
void	ps_rrr(t_stacks *stacks);
void	ps_quick_sort(t_stacks *stacks);
void	quicksort(int *arr, int low, int high);
int		find_pivot(t_list *s, int count, int flag);
void	qs_ta(t_stacks *stacks, int size);
void	qs_ba(t_stacks *stacks, int size);
void	qs_tb(t_stacks *stacks, int size);
void	qs_bb(t_stacks *stacks, int size);
t_list	*ft_lstfrange(t_list *lst, int size);

//stacks utils
int		init_idx(t_stacks *stacks);
int		chk_dupes(t_stacks *stacks, int *n);
int		chk_isort(t_stacks *stacks);
int		init_a(t_stacks *stacks, char *av);
void	free_stacks(t_stacks *stacks);
void	free_split(char **str);
void	free_ds(t_stacks *stacks);
int		chck_arg(t_stacks *stacks, char **av);
int		chk_split(char **str);
int		chk_atoi(const char *nptr);

//op utils
void	op_init(t_stacks *stacks);
void	op_ins(t_stacks *stacks, char *str);
void	op_print(t_stacks *stacks);
void	op_print_eof(t_stacks *stacks);

//print utils
void	print_stack(t_stacks *stacks);
void	print_ds(t_stacks *stacks);
void	split_print(char **str);

#endif
