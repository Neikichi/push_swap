/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:03:44 by vlow              #+#    #+#             */
/*   Updated: 2024/12/29 02:44:41 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void		is_fa(t_stacks *stacks);
// static void		is_fb(t_stacks *stacks);

void	is_init(t_stacks *stacks)
{
	int step = stacks->size / 6;
	int pivot = step; 
	int count = 0;

	while (ft_lstsize(stacks->a) > 3)
	{
		if (stacks->a->idx <= pivot)
		{
			ps_pb(stacks);
			count++;
			if (stacks->b->idx <= pivot - step / 2 && ft_lstsize(stacks->b) >= 2)
				ps_rb(stacks);
			if (count == pivot)
			{
				pivot += step;
				if (pivot >= stacks->size - 3)
					pivot = stacks->size - 3;
			}
		}
		else
			ps_ra(stacks);
	}
	
	ps_simple(stacks, 0);
	while (stacks->b)
	{
		is_fa(stacks);
	}
	while (stacks->size != stacks->ea->idx)
	{
		ps_simple(stacks, 0);
		ps_rra(stacks);
	}
	ps_simple(stacks, 0);
}

static void	is_fa(t_stacks *stacks)
{
	while (stacks->b)
	{
		int target = stacks->a->idx - 1;
		int xfdb = ft_lstrange(stacks->b, target);
		int xrdb = ft_lstrrange(stacks->b, target);

		if (target == stacks->b->idx)
		{
			ps_pa(stacks);
		}
		else if (target - 1 == stacks->b->idx)
		{
			ps_pa(stacks);
			ps_ra(stacks);
		}
		else if (xfdb == -1)
		{
			while (stacks->ea->idx != stacks->size)
			{
				ps_simple(stacks, 0);
				ps_rra(stacks);
			}
			ps_simple(stacks, 0);
		}
		else if (xfdb <= xrdb)
			while (stacks->b->idx != target)
				ps_rb(stacks);
		else
		{
			while (stacks->b->idx != target)
				ps_rrb(stacks);
		}
	}
}
//
// static void	is_fb(t_stacks *stacks)
// {
// 	while (stacks->b)
// 	{
// 		int target = stacks->b->idx + 1;
// 		int fdist = ft_lstrange(stacks->a, target);
// 		int rdist = ft_lstrrange(stacks->a, target);
//
// 		if (target == stacks->a->idx)
// 		{
// 			ps_pa(stacks);
// 		}
// 		else if (fdist == -1)
// 		{
// 			break ;
// 		}
// 		else if (fdist <= rdist)
// 			while (stacks->a->idx != target)
// 				ps_ra(stacks);
// 		else
// 		{
// 			while (stacks->a->idx != target)
// 				ps_rra(stacks);
// 		}
// 	}
// }
