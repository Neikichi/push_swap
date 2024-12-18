/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:25:53 by vlow              #+#    #+#             */
/*   Updated: 2024/12/18 15:51:47 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_simple_a(t_stacks *stacks)
{
	while (chk_isort(stacks))
	{
		if (stacks->a->idx == stacks->size)
			ps_ra(stacks);
		else if (stacks->a->idx > stacks->a->next->idx)
			ps_sa(stacks);
		else
			ps_rra(stacks);
	}
}

void	ps_simple_b(t_stacks *stacks)
{
	while (chk_isort(stacks))
	{
		if (stacks->b->idx == stacks->size)
			ps_ra(stacks);
		else if (stacks->b->idx > stacks->b->next->idx)
			ps_sa(stacks);
		else
			ps_rra(stacks);
	}
}

void	ps_simple_ex(t_stacks *stacks)
{
	while (chk_isort(stacks) || stacks->b)
	{
		if (stacks->a->idx > stacks->a->next->idx && stacks->a->idx != stacks->size)
			ps_sa(stacks);
		else if (ft_lstsize(stacks->a) > 3 && stacks->a->idx < 3)
			ps_pb(stacks);
		else if (ft_lstsize(stacks->a) > 3)
			ps_ra(stacks);
		if (ft_lstsize(stacks->a) <= 3)
			ps_simple_a(stacks);
		if (!chk_isort(stacks))
		{
			while (stacks->b)
			{
				if (ft_lstsize(stacks->b) > 1 && stacks->b->idx < stacks->b->next->idx)
					ps_sb(stacks);
				else
					ps_pa(stacks);
			}
		}
	}
}


