/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:25:53 by vlow              #+#    #+#             */
/*   Updated: 2024/12/24 03:17:07 by vlow             ###   ########.fr       */
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
    // // Ensure stack_b has at least three elements
    // if (!stacks->b || !stacks->b->next || !stacks->b->next->next)
    //     return;
    //
    int a = stacks->b->idx;
    int b = stacks->b->next->idx;
    int c = stacks->b->next->next->idx;

    // Already sorted in descending order
    if (a > b && b > c)
        return;
    // a > c > b: Bring c to top, swap to correct order
    else if (a > c && c > b) {
        ps_rrb(stacks); // Rotate downwards
        ps_sb(stacks);  // Swap top two
    }
    // b > a > c: Swap top two
    else if (b > a && a > c) {
        ps_sb(stacks);
    }
    // b > c > a: Rotate upwards
    else if (b > c && c > a) {
        ps_rb(stacks);
    }
    // c > a > b: Swap and rotate upwards
    else if (c > a && a > b) {
        ps_sb(stacks);
        ps_rb(stacks);
    }
    // c > b > a: Swap and rotate downwards
    else if (c > b && b > a) {
        ps_sb(stacks);
        ps_rrb(stacks);
    }
}

void ps_simple(t_stacks *stacks, int z)
{
	int za = ft_lstsize(stacks->a);
	int zb = ft_lstsize(stacks->b);

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
	if (!stacks || !stacks->a || !stacks->a->next || !stacks->a->next->next)
		return ;

	int a = stacks->a->idx;             // top
	int b = stacks->a->next->idx;       // second
	int c = stacks->a->next->next->idx; // third

	if ((a < b) && (b < c) && (a < c))
		return ;
	// 1) (a <= b) && (b > c) && (a > c)
	//    --> Matches permutation (2,3,1)
	else if ((a <= b) && (b > c) && (a > c))
	{
		ps_ra(stacks);
		ps_sa(stacks);
		ps_rra(stacks);
		ps_sa(stacks);
	}

	// 2) (a > b) && (b <= c) && (a > c)
	//    --> Matches permutation (3,1,2)
	else if ((a > b) && (b <= c) && (a > c))
	{
		ps_sa(stacks);
		ps_ra(stacks);
		ps_sa(stacks);
		ps_rra(stacks);
	}

	// 3) (a <= b) && (b > c) && (a <= c)
	//    --> Matches permutation (1,3,2)
	else if ((a <= b) && (b > c) && (a <= c))
	{
		ps_ra(stacks);
		ps_sa(stacks);
		ps_rra(stacks);
	}

	// 4) (a > b) && (b <= c) && (a <= c)
	//    --> Matches permutation (2,1,3)
	else if ((a > b) && (b <= c) && (a <= c))
	{
		ps_sa(stacks);
	}

	// 6) (a > b) && (b > c) && (a > c)
	//    --> Matches permutation (3,2,1)
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
	if (!stacks || !stacks->b || !stacks->b->next || !stacks->b->next->next)
		return;

	int a = stacks->b->idx;              // Top of B
	int b = stacks->b->next->idx;        // Second of B
	int c = stacks->b->next->next->idx;  // Third of B

	// (3,2,1) => Already descending => do nothing
	if ((a > b) && (b > c) && (a > c))
	{
		return; 
	}

	// (3,1,2) => (a>b, b<c, a>c)
	else if ((a > b) && (b < c) && (a > c))
	{
		// Sequence to fix (3,1,2) -> (3,2,1)
		ps_rb(stacks);
		ps_sb(stacks);
		ps_rrb(stacks);
	}

	// (2,3,1) => (a<b, b>c, a>c)
	else if ((a < b) && (b > c) && (a > c))
	{
		// Sequence to fix (2,3,1) -> (3,2,1)
		ps_sb(stacks);
	}

	// (2,1,3) => (a>b, b<c, a<c)
	else if ((a > b) && (b < c) && (a < c))
	{
		// Minimal fix: Just swap top two => (2,1,3)->(3,1,2),
		// then next pass might fix further, or this may suffice 
		// if you only have exactly 3 elements in B.
		ps_rb(stacks);
		ps_sb(stacks);
		ps_rrb(stacks);
		ps_sb(stacks);
	}

	// (1,3,2) => (a<b, b>c, a<c)
	else if ((a < b) && (b > c) && (a < c))
	{
		// Sequence to fix (1,3,2)->(3,1,2)->(3,2,1)
		ps_sb(stacks);
		ps_rb(stacks);
		ps_sb(stacks);
		ps_rrb(stacks);
	}

	// (1,2,3) => (a<b, b<c, a<c) => fully ascending
	// we want (3,2,1), so bigger fix:
	else // if ((a < b) && (b < c) && (a < c))
	{
		// Sequence to fix (1,2,3)->(3,2,1)
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


