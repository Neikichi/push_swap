/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:03:44 by vlow              #+#    #+#             */
/*   Updated: 2024/12/18 18:44:51 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_sort(t_stacks *stacks)
{
	int cs = stacks->size - (stacks->size / 3 * 2);

	while (chk_isort(stacks) || stacks->b)
	{
		int ic = ps_ic(stacks->a->idx, stacks->size);

		if (ft_lstsize(stacks->a) == cs)
			break ;
		if (ic == 1)
		{
			ps_sc(stacks);
			// a function to either swap it big n small
			// then move it to b, do i need to sort it before
			// rotate to bot?
		}
		if (ic == 2)
		{
			ps_mc(stacks);
			// mid chunk, so this have to be small then big
			// then push to top of b. or can just swap there.
		}
		if (ic == 3)
		{
			ps_lc(stacks);
			// basically the biggest range left in a, 
			// to be sorted once mid and small sent to b
		}
	}
	ps_qs(stacks);
}

void	ps_qs(t_stacks *stacks)
{
	while (chk_isort(stacks))
	{
		if (stacks->a->idx > stacks->a->next->idx)
		{
			ps_pb(stacks);
		}
		ps_ra(stacks);
	}
}

void	ps_sc(t_stacks *stacks)
{
	int ic = ps_ic(stacks->a->idx, stacks->size);
	int icn = ps_ic(stacks->a->next->idx, stacks->size);

	if (ic == icn)
	{
		if (stacks->a->idx > stacks->a->next->idx)
			ps_sa(stacks);
	}
	if (stacks->b && ps_ic(stacks->b->idx, stacks->size) == 1)
	{
		if (stacks->a->idx > stacks->b->idx && ft_lstsize(stacks->b) > 1)
			ps_rb(stacks);
	}
	ps_pb(stacks);
	ps_rb(stacks);
}

void	ps_mc(t_stacks *stacks)
{
	int ic = ps_ic(stacks->a->idx, stacks->size);
	int icn = ps_ic(stacks->a->next->idx, stacks->size);

	if (ic == icn)
	{
		if (stacks->a->idx > stacks->a->next->idx)
			ps_sa(stacks);
	}
	if (stacks->b && ps_ic(stacks->b->idx, stacks->size) == 2)
	{
		if (stacks->a->idx < stacks->b->idx && ft_lstsize(stacks->b) > 1)
		{
			ps_rb(stacks);
			ps_pb(stacks);
			ps_rrb(stacks);
		}
		else
			ps_pb(stacks);
	}
	else
		ps_pb(stacks);
}

void	ps_lc(t_stacks *stacks)
{
	int ic = ps_ic(stacks->a->idx, stacks->size);
	int icn = ps_ic(stacks->a->next->idx, stacks->size);

	if (ic == icn)
	{
		if (stacks->a->idx < stacks->a->next->idx)
			ps_sa(stacks);
	}
	ps_ra(stacks);
}

int	ps_ic(int idx, int size)
{
	int chunk_size = size / 3;

	if (idx <= chunk_size)
		return (1);
	else if (idx <= chunk_size * 2)
		return (2);
	else
		return (3);
}
