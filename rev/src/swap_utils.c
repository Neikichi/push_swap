/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:32:20 by vlow              #+#    #+#             */
/*   Updated: 2024/12/13 01:37:24 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_sa(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->a && stacks->a->next)
	{
		temp = stacks->a->next;
		stacks->a->next = temp->next;
		temp->next = stacks->a;
		stacks->a = temp;
		ft_putstr_fd("sa\n", 1);
	}
}

void	ps_sb(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->b && stacks->b->next)
	{
		temp = stacks->b->next;
		stacks->b->next = temp->next;
		temp->next = stacks->b;
		stacks->b = temp;
		ft_putstr_fd("sb\n", 1);
	}
}

void	ps_ss(t_stacks *stacks)
{
	ps_sa(stacks);
	ps_sb(stacks);
	ft_putstr_fd("ss\n", 1);
}

void	ps_pa(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->b)
	{
		temp = stacks->b;
		stacks->b = stacks->b->next;
		temp->next = NULL;
		ft_lstadd_front(&stacks->a, temp);
		ft_putstr_fd("pa\n", 1);
	}
}

void	ps_pb(t_stacks *stacks)
{
	t_list	*temp;

	if (stacks->a)
	{
		temp = stacks->a;
		stacks->a = stacks->a->next;
		temp->next = NULL;
		ft_lstadd_front(&stacks->b, temp);
		ft_putstr_fd("pb\n", 1);
	}
}
