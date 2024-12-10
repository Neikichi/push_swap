/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:11:57 by vlow              #+#    #+#             */
/*   Updated: 2024/12/10 18:39:45 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stacks
{
	struct s_list	*a;
	struct s_list	*b;
}	t_stacks;
// can use the libft list with void ptr.
// typedef struct s_node
// {
// 	int				i;
// 	struct s_node	*next;
// }	t_node;


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

#endif
