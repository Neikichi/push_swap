/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:48:01 by vlow              #+#    #+#             */
/*   Updated: 2024/12/29 21:36:37 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	qs_tb_partition(t_stacks *stacks, int *arr, int size);
static void	qs_bb_partition(t_stacks *stacks, int *arr, int size);

//	arr[5] = pivot1, pivot2, bz, mz, sz
void	qs_tb(t_stacks *stacks, int size)
{
	int	arr[5];

	if (size <= 3)
	{
		ps_simple(stacks, 1);
		while (size--)
			ps_pa(stacks);
		return ;
	}
	ft_memset(arr, 0, sizeof(arr));
	arr[0] = find_pivot(stacks->b, size, 0);
	arr[1] = find_pivot(stacks->b, size, 1);
	qs_tb_partition(stacks, arr, size);
	qs_ta(stacks, arr[2]);
	qs_ba(stacks, arr[3]);
	if (ft_lstsize(stacks->b) == arr[4])
		qs_tb(stacks, arr[4]);
	else
		qs_bb(stacks, arr[4]);
}

static void	qs_tb_partition(t_stacks *stacks, int *arr, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if (stacks->b->idx <= arr[0])
		{
			ps_rb(stacks);
			arr[4]++;
		}
		else if (stacks->b->idx > arr[0] && stacks->b->idx <= arr[1])
		{
			ps_pa(stacks);
			ps_ra(stacks);
			arr[3]++;
		}
		else
		{
			ps_pa(stacks);
			arr[2]++;
		}
	}
}

void	qs_bb(t_stacks *stacks, int size)
{
	int	arr[5];

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
	ft_memset(arr, 0, sizeof(arr));
	arr[0] = find_pivot(ft_lstfrange(stacks->b, \
				ft_lstsize(stacks->b) - size), size, 0);
	arr[1] = find_pivot(ft_lstfrange(stacks->b, \
				ft_lstsize(stacks->b) - size), size, 1);
	qs_bb_partition(stacks, arr, size);
	qs_ta(stacks, arr[2]);
	qs_tb(stacks, arr[3]);
	qs_ba(stacks, arr[4]);
}

static void	qs_bb_partition(t_stacks *stacks, int *arr, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if (stacks->eb->idx <= arr[0])
		{
			ps_rrb(stacks);
			ps_pa(stacks);
			ps_ra(stacks);
			arr[4]++;
		}
		else if (stacks->eb->idx > arr[0] && stacks->eb->idx <= arr[1])
		{
			ps_rrb(stacks);
			arr[3]++;
		}
		else
		{
			ps_rrb(stacks);
			ps_pa(stacks);
			arr[2]++;
		}
	}
}

t_list	*ft_lstfrange(t_list *lst, int size)
{
	while (lst)
	{
		size--;
		if (!size)
			break ;
		lst = lst->next;
	}
	if (!lst)
		return (NULL);
	return (lst);
}
