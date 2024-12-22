/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:11:57 by vlow              #+#    #+#             */
/*   Updated: 2024/12/22 15:55:08 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stacks
{
	struct s_list	*a;
	struct s_list	*b;
	struct s_list	*ds;
	t_list			*ea;
	t_list			*eb;
	int				size;
}	t_stacks;
// can use the libft list with void ptr.
// typedef struct s_node
// {
// 	int				i;
// 	struct s_node	*next;
// }	t_node;

//push swap
void	ps_init(t_stacks *stacks);
void	ps_simple_a(t_stacks *stacks);
void	ps_simple_b(t_stacks *stacks);
void	ps_simple_ex(t_stacks *stacks);
void	ps_sort(t_stacks *stacks);
int		ps_ic(int idx, int size);
void	ps_sc(t_stacks *stacks);
void	ps_mc(t_stacks *stacks);
void	ps_lc(t_stacks *stacks);
void	ps_qs(t_stacks *stacks);

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

//print utils
void	print_stack(t_stacks *stacks);
void	print_ds(t_stacks *stacks);
void	split_print(char **str);

void ps_quick_sort(t_stacks *stacks);
void quicksort(int *arr, int low, int high);
int find_median(t_list *s, int count);

#endif
