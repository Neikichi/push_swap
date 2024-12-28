/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:36:33 by vlow              #+#    #+#             */
/*   Updated: 2024/12/28 22:07:36 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	qs_ta(t_stacks *stacks, int size);
void	qs_ba(t_stacks *stacks, int size);
void	qs_tb(t_stacks *stacks, int size);
void	qs_bb(t_stacks *stacks, int size);
static t_list	*ft_lstfrange(t_list *lst, int size);

void qs_init(t_stacks *stacks)
{
	qs_ta(stacks, stacks->size);
}

void	qs_ta(t_stacks *stacks, int size)
{
	if (size <= 3)
	{
		ps_simple(stacks, 0);
		return ;
	}

	int pivot = find_pivot(stacks->a, size, 0);
	int pivot2 = find_pivot(stacks->a, size, 1);
	int bz = 0;
	int mz = 0;
	int sz = 0;
	int i = 0;

	while (i++ < size)
	{
		if (stacks->a->idx <= pivot)
		{
			ps_pb(stacks);
			ps_rb(stacks);
			sz++;
		}
		else if (stacks->a->idx > pivot && stacks->a->idx <= pivot2)
		{
			ps_pb(stacks);
			mz++;
		}
		else
		{
			ps_ra(stacks);
			bz++;
		}
	}
	if (ft_lstsize(stacks->a) == bz)
		qs_ta(stacks, bz);
	else
		qs_ba(stacks, bz);
	qs_tb(stacks, mz);
	if (ft_lstsize(stacks->b) == sz)
		qs_tb(stacks, sz);
	else
		qs_bb(stacks, sz);
	
}

void	qs_ba(t_stacks *stacks, int size)
{
	if (size <= 3)
	{
		while (size--)
			ps_rra(stacks);
		ps_simple(stacks, 0);
		return ;
	}
	int pivot = find_pivot(ft_lstfrange(stacks->a, ft_lstsize(stacks->a) - size), size, 0);
	int pivot2 = find_pivot(ft_lstfrange(stacks->a, ft_lstsize(stacks->a) - size), size, 1);
	int bz = 0;
	int mz = 0;
	int sz = 0;
	int i = 0;

	while (i++ < size)
	{
		ps_rra(stacks);
		if (stacks->a->idx <= pivot)
		{
			ps_pb(stacks);
			ps_rb(stacks);
			sz++;
		}
		else if (stacks->a->idx > pivot && stacks->a->idx <= pivot2)
		{
			ps_pb(stacks);
			mz++;
		}
		else
		{
			bz++;
		}
	}
	qs_ta(stacks, bz);
	qs_tb(stacks, mz);
	if (ft_lstsize(stacks->b) == sz)
		qs_tb(stacks, sz);
	else
		qs_bb(stacks, sz);
}

void	qs_tb(t_stacks *stacks, int size)
{
	if (size <= 3)
	{
		ps_simple(stacks, 1);
		while (size--)
			ps_pa(stacks);
		return ;
	}

	int pivot = find_pivot(stacks->b, size, 0);
	int pivot2 = find_pivot(stacks->b, size, 1);
	int i = 0;
	int bz = 0;
	int mz = 0;
	int sz = 0;

	while (i++ < size)
	{
		if (stacks->b->idx <= pivot)
		{
			ps_rb(stacks);
			sz++;
		}
		else if (stacks->b->idx > pivot && stacks->b->idx <= pivot2)
		{
			ps_pa(stacks);
			ps_ra(stacks);
			mz++;
		}
		else
		{
			ps_pa(stacks);
			bz++;
		}
	}
	qs_ta(stacks, bz);
	qs_ba(stacks, mz);
	if (ft_lstsize(stacks->b) == sz)
		qs_tb(stacks, sz);
	else
		qs_bb(stacks, sz);

}

void	qs_bb(t_stacks *stacks, int size)
{
	if (size <= 3)
	{
		while (size--)
		{
			ps_rrb(stacks);
			ps_pa(stacks);
		}
		ps_simple(stacks, 0);
		return ;
	}

	int pivot = find_pivot(ft_lstfrange(stacks->b, ft_lstsize(stacks->b) - size), size, 0);
	int pivot2 = find_pivot(ft_lstfrange(stacks->b, ft_lstsize(stacks->b) - size), size, 1);
	int i = 0;
	int bz = 0;
	int mz = 0;
	int sz = 0;

	while (i++ < size)
	{
		if (stacks->eb->idx <= pivot)
		{
			ps_rrb(stacks);
			ps_pa(stacks);
			ps_ra(stacks);
			sz++;
		}
		else if (stacks->eb->idx > pivot && stacks->eb->idx <= pivot2)
		{
			ps_rrb(stacks);
			mz++;
		}
		else
		{
			ps_rrb(stacks);
			ps_pa(stacks);
			bz++;
		}
	}
	qs_ta(stacks, bz);
	qs_tb(stacks, mz);
	qs_ba(stacks, sz);
}

static t_list	*ft_lstfrange(t_list *lst, int size)
{
	while (lst)
	{
		size--;
		if (!size)
			break;
		lst = lst->next;
	}
	if (!lst)
		return (NULL);
	return (lst);
}
