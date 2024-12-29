/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:25:53 by vlow              #+#    #+#             */
/*   Updated: 2024/12/29 14:13:33 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	ps_simple_3b_h(t_stacks *stacks, int a, int b, int c);
static void	ps_simple_3a_h(t_stacks *stacks, int a, int b, int c);

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
	else if ((a <= b) && (b > c) && (a <= c))
	{
		ps_ra(stacks);
		ps_sa(stacks);
		ps_rra(stacks);
	}
	else if ((a > b) && (b <= c) && (a <= c))
		ps_sa(stacks);
	else
		ps_simple_3a_h(stacks, a, b, c);
}

static void	ps_simple_3a_h(t_stacks *stacks, int a, int b, int c)
{
	if ((a > b) && (b > c) && (a > c))
	{
		ps_sa(stacks);
		ps_ra(stacks);
		ps_sa(stacks);
		ps_rra(stacks);
		ps_sa(stacks);
	}
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
		return ;
	else if ((a > b) && (b < c) && (a > c))
	{
		ps_rb(stacks);
		ps_sb(stacks);
		ps_rrb(stacks);
	}
	else if ((a < b) && (b > c) && (a > c))
		ps_sb(stacks);
	else
		ps_simple_3b_h(stacks, a, b, c);
}

static void	ps_simple_3b_h(t_stacks *stacks, int a, int b, int c)
{
	if ((a > b) && (b < c) && (a < c))
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
