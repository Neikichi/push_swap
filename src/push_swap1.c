/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:25:53 by vlow              #+#    #+#             */
/*   Updated: 2024/12/29 03:32:38 by vlow             ###   ########.fr       */
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
	{
		ps_sb(stacks);
	}
	else if (b > c && c > a)
	{
		ps_rb(stacks);
	}
	else if (c > a && a > b)
	{
		ps_sb(stacks);
		ps_rb(stacks);
	}
	else if (c > b && b > a)
	{
		ps_sb(stacks);
		ps_rrb(stacks);
	}
}

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
}

void	ps_simple_3a(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	if (!stacks || !stacks->a || !stacks->a->next || !stacks->a->next->next)
		return ;
	a = stacks->a->idx;
	b = stacks->a->next->idx;
	c = stacks->a->next->next->idx;
	if ((a < b) && (b < c) && (a < c))
		return ;
	else if ((a <= b) && (b > c) && (a > c))
	{
		ps_ra(stacks);
		ps_sa(stacks);
		ps_rra(stacks);
		ps_sa(stacks);
	}
	else if ((a > b) && (b <= c) && (a > c))
	{
		ps_sa(stacks);
		ps_ra(stacks);
		ps_sa(stacks);
		ps_rra(stacks);
	}
	else if ((a <= b) && (b > c) && (a <= c))
	{
		ps_ra(stacks);
		ps_sa(stacks);
		ps_rra(stacks);
	}
	else if ((a > b) && (b <= c) && (a <= c))
	{
		ps_sa(stacks);
	}
	else if ((a > b) && (b > c) && (a > c))
	{
		ps_sa(stacks);
		ps_ra(stacks);
		ps_sa(stacks);
		ps_rra(stacks);
		ps_sa(stacks);
	}
}

void	ps_simple_3b(t_stacks *stacks)
{
	int	a;
	int	b;
	int	c;

	if (!stacks || !stacks->b || !stacks->b->next || !stacks->b->next->next)
		return ;
	a = stacks->b->idx;
	b = stacks->b->next->idx;
	c = stacks->b->next->next->idx;
	if ((a > b) && (b > c) && (a > c))
	{
		return ;
	}
	else if ((a > b) && (b < c) && (a > c))
	{
		ps_rb(stacks);
		ps_sb(stacks);
		ps_rrb(stacks);
	}
	else if ((a < b) && (b > c) && (a > c))
	{
		ps_sb(stacks);
	}
	else if ((a > b) && (b < c) && (a < c))
	{
		ps_rb(stacks);
		ps_sb(stacks);
		ps_rrb(stacks);
		ps_sb(stacks);
	}
	else if ((a < b) && (b > c) && (a < c))
	{
		ps_sb(stacks);
		ps_rb(stacks);
		ps_sb(stacks);
		ps_rrb(stacks);
	}
	else
	{
		ps_sb(stacks);
		ps_rb(stacks);
		ps_sb(stacks);
		ps_rrb(stacks);
		ps_sb(stacks);
	}
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
