/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:34:27 by vlow              #+#    #+#             */
/*   Updated: 2024/12/29 02:02:02 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_ra(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->a)
	{
		temp = stacks->a;
		stacks->a = stacks->a->next;
		temp->next = NULL;
		ft_lstadd_back(&stacks->a, temp);
		stacks->ea = temp;
		op_ins(stacks, "ra");
	}
}

void	ps_rb(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->b)
	{
		temp = stacks->b;
		stacks->b = stacks->b->next;
		temp->next = NULL;
		ft_lstadd_back(&stacks->b, temp);
		stacks->eb = temp;
		op_ins(stacks, "rb");
	}
}

void	ps_rra(t_stacks *stacks)
{
	t_list	*temp;
	t_list	*prev;

	if (ft_lstsize(stacks->a) > 2)
	{
		temp = stacks->a;
		while (temp->next)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		ft_lstadd_front(&stacks->a, temp);
		stacks->ea = prev;
		op_ins(stacks, "rra");
	}
}

void	ps_rrb(t_stacks *stacks)
{
	t_list	*temp;
	t_list	*prev;

	if (ft_lstsize(stacks->b) > 2)
	{
		temp = stacks->b;
		while (temp->next)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		ft_lstadd_front(&stacks->b, temp);
		stacks->eb = prev;
		op_ins(stacks, "rrb");
	}
}
