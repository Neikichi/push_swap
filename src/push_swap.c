/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:11:59 by vlow              #+#    #+#             */
/*   Updated: 2024/12/31 00:04:11 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_init(t_stacks *stacks)
{
	if (stacks->size <= 3)
	{
		ps_simple_a(stacks);
	}
	if (stacks->size > 3 && stacks->size <= 5)
	{
		ps_simple_ex(stacks);
	}
	if (stacks->size > 5 && stacks->size <= 100)
	{
		is_init(stacks);
	}
	if (stacks->size > 100)
		qs_init(stacks);
}

void	ps_simple_2a(t_stacks *stacks)
{
	if (stacks->a->idx > stacks->a->next->idx)
	{
		ps_sa(stacks);
	}
}

void	ps_simple_2b(t_stacks *stacks)
{
	if (stacks->b->idx < stacks->b->next->idx)
	{
		ps_sb(stacks);
	}
}

void	ps_simple_ex(t_stacks *stacks)
{
	while (chk_isort(stacks) || stacks->b)
	{
		if (stacks->a->idx > stacks->a->next->idx
			&& stacks->a->idx != stacks->size)
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
				if (ft_lstsize(stacks->b) > 1
					&& stacks->b->idx < stacks->b->next->idx)
					ps_sb(stacks);
				else
					ps_pa(stacks);
			}
		}
	}
}
