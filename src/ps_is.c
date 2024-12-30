/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:03:44 by vlow              #+#    #+#             */
/*   Updated: 2024/12/29 14:34:36 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	is_init_h(t_stacks *stacks, int *inc, int *pvt, int *cnt);
static void	is_fa(t_stacks *stacks);
static void	is_fa_na(t_stacks *stacks);
static void	is_fa_h(t_stacks *stacks, int target, int opt);

void	is_init(t_stacks *stacks)
{
	int	inc;
	int	pvt;
	int	cnt;

	inc = stacks->size / 6;
	pvt = inc;
	cnt = 0;
	is_init_h(stacks, &inc, &pvt, &cnt);
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

static void	is_init_h(t_stacks *stacks, int *inc, int *pvt, int *cnt)
{
	while (ft_lstsize(stacks->a) > 3)
	{
		if (stacks->a->idx <= *pvt)
		{
			ps_pb(stacks);
			(*cnt)++;
			if (stacks->b->idx <= *pvt - *inc / 2 && ft_lstsize(stacks->b) >= 2)
				ps_rb(stacks);
			if (*cnt == *pvt)
			{
				*pvt += *inc;
				if (*pvt >= stacks->size - 3)
					*pvt = stacks->size - 3;
			}
		}
		else
			ps_ra(stacks);
	}
}

static void	is_fa(t_stacks *stacks)
{
	int	target;
	int	xfdb;
	int	xrdb;

	while (stacks->b)
	{
		target = stacks->a->idx - 1;
		xfdb = ft_lstrange(stacks->b, target);
		xrdb = ft_lstrrange(stacks->b, target);
		if (target == stacks->b->idx)
			ps_pa(stacks);
		else if (target - 1 == stacks->b->idx)
		{
			ps_pa(stacks);
			ps_ra(stacks);
		}
		else if (xfdb == -1)
			is_fa_na(stacks);
		else if (xfdb <= xrdb)
			is_fa_h(stacks, target, 0);
		else
			is_fa_h(stacks, target, 1);
	}
}

static void	is_fa_na(t_stacks *stacks)
{
	while (stacks->ea->idx != stacks->size)
	{
		ps_simple(stacks, 0);
		ps_rra(stacks);
	}
	ps_simple(stacks, 0);
}

static void	is_fa_h(t_stacks *stacks, int target, int opt)
{
	if (!opt)
	{
		while (stacks->b->idx != target)
			ps_rb(stacks);
	}
	else
	{
		while (stacks->b->idx != target)
			ps_rrb(stacks);
	}
}
