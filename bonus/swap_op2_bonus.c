/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_op2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:34:27 by vlow              #+#    #+#             */
/*   Updated: 2024/12/30 22:19:02 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	b_ra(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->a)
	{
		temp = stacks->a;
		stacks->a = stacks->a->next;
		temp->next = NULL;
		ft_lstadd_back(&stacks->a, temp);
		stacks->ea = temp;
	}
}

void	b_rb(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->b)
	{
		temp = stacks->b;
		stacks->b = stacks->b->next;
		temp->next = NULL;
		ft_lstadd_back(&stacks->b, temp);
		stacks->eb = temp;
	}
}

void	b_rra(t_stacks *stacks)
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
	}
}

void	b_rrb(t_stacks *stacks)
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
	}
}
