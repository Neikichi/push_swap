/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:25:53 by vlow              #+#    #+#             */
/*   Updated: 2025/01/02 14:58:03 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ps_simple_h(t_stacks *stacks, int zb);
static void	ps_simple_b_h(t_stacks *stacks, int a, int b, int c);

void	ps_simple(t_stacks *stacks, int z)
{
	int	za;
	int	zb;

	za = ft_lstsize(stacks->a);
	zb = ft_lstsize(stacks->b);
	if (!z)
	{
		if (za < 2)
			return ;
		if (za == 2)
			ps_simple_2a(stacks);
		if (za == 3)
			ps_simple_a(stacks);
		else
			ps_simple_3a(stacks);
	}
	else
		ps_simple_h(stacks, zb);
}

static void	ps_simple_h(t_stacks *stacks, int zb)
{
	if (zb < 2)
		return ;
	if (zb == 2)
		ps_simple_2b(stacks);
	if (zb == 3)
		ps_simple_b(stacks);
	else
		ps_simple_3b(stacks);
}

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
	int	a;
	int	b;
	int	c;

	a = stacks->b->idx;
	b = stacks->b->next->idx;
	c = stacks->b->next->next->idx;
	if (a > b && b > c)
		return ;
	else if (a > c && c > b)
	{
		ps_rrb(stacks);
		ps_sb(stacks);
	}
	else if (b > a && a > c)
		ps_sb(stacks);
	else if (b > c && c > a)
		ps_rb(stacks);
	else
		ps_simple_b_h(stacks, a, b, c);
}

static void	ps_simple_b_h(t_stacks *stacks, int a, int b, int c)
{
	if (c > a && a > b)
	{
		ps_rrb(stacks);
	}
	else if (c > b && b > a)
	{
		ps_sb(stacks);
		ps_rrb(stacks);
	}
}
