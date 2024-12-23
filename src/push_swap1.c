/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:25:53 by vlow              #+#    #+#             */
/*   Updated: 2024/12/23 16:24:26 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_simple_a(t_stacks *stacks)
{
    // Ensure stack_a has at least three elements
    if (!stacks->a || !stacks->a->next || !stacks->a->next->next)
        return;

    int a = stacks->a->idx;
    int b = stacks->a->next->idx;
    int c = stacks->a->next->next->idx;

    // Already sorted in ascending order
    if (a < b && b < c)
        return;
    // a < c < b: Bring c to top, swap to correct order
    else if (a < c && c < b) {
        ps_rra(stacks); // Rotate downwards
        ps_sa(stacks);  // Swap top two
    }
    // b < a < c: Swap top two
    else if (b < a && a < c) {
        ps_sa(stacks);
    }
    // b < c < a: Rotate upwards
    else if (b < c && c < a) {
        ps_ra(stacks);
    }
    // c < a < b: Swap and rotate upwards
    else if (c < a && a < b) {
        ps_sa(stacks);
        ps_ra(stacks);
    }
    // c < b < a: Swap and rotate downwards
    else if (c < b && b < a) {
        ps_sa(stacks);
        ps_rra(stacks);
    }
	// while (chk_isort(stacks))
	// {
	// 	if (stacks->a->idx == stacks->size)
	// 		ps_ra(stacks);
	// 	else if (stacks->a->idx > stacks->a->next->idx)
	// 		ps_sa(stacks);
	// 	else
	// 		ps_rra(stacks);
	// }
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


