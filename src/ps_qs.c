/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_qs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 18:36:33 by vlow              #+#    #+#             */
/*   Updated: 2024/12/29 21:32:26 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	qs_ta_partition(t_stacks *stacks, int *arr, int size);
static void	qs_ba_partition(t_stacks *stacks, int *arr, int size);

void	qs_init(t_stacks *stacks)
{
	qs_ta(stacks, stacks->size);
}

//	arr[5] = pivot1, pivot2, bz, mz, sz
void	qs_ta(t_stacks *stacks, int size)
{
	int	arr[5];

	if (size <= 3)
	{
		ps_simple(stacks, 0);
		return ;
	}
	ft_memset(arr, 0, sizeof(arr));
	arr[0] = find_pivot(stacks->a, size, 0);
	arr[1] = find_pivot(stacks->a, size, 1);
	qs_ta_partition(stacks, arr, size);
	if (ft_lstsize(stacks->a) == arr[2])
		qs_ta(stacks, arr[2]);
	else
		qs_ba(stacks, arr[2]);
	qs_tb(stacks, arr[3]);
	if (ft_lstsize(stacks->b) == arr[4])
		qs_tb(stacks, arr[4]);
	else
		qs_bb(stacks, arr[4]);
}

static void	qs_ta_partition(t_stacks *stacks, int *arr, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		if (stacks->a->idx <= arr[0])
		{
			ps_pb(stacks);
			ps_rb(stacks);
			arr[4]++;
		}
		else if (stacks->a->idx > arr[0] && stacks->a->idx <= arr[1])
		{
			ps_pb(stacks);
			arr[3]++;
		}
		else
		{
			ps_ra(stacks);
			arr[2]++;
		}
	}
}

void	qs_ba(t_stacks *stacks, int size)
{
	int	arr[5];

	if (size <= 3)
	{
		while (size--)
			ps_rra(stacks);
		ps_simple(stacks, 0);
		return ;
	}
	ft_memset(arr, 0, sizeof(arr));
	arr[0] = find_pivot(ft_lstfrange(stacks->a, \
				ft_lstsize(stacks->a) - size), size, 0);
	arr[1] = find_pivot(ft_lstfrange(stacks->a, \
				ft_lstsize(stacks->a) - size), size, 1);
	qs_ba_partition(stacks, arr, size);
	qs_ta(stacks, arr[2]);
	qs_tb(stacks, arr[3]);
	if (ft_lstsize(stacks->b) == arr[4])
		qs_tb(stacks, arr[4]);
	else
		qs_bb(stacks, arr[4]);
}

static void	qs_ba_partition(t_stacks *stacks, int *arr, int size)
{
	int	i;

	i = 0;
	while (i++ < size)
	{
		ps_rra(stacks);
		if (stacks->a->idx <= arr[0])
		{
			ps_pb(stacks);
			ps_rb(stacks);
			arr[4]++;
		}
		else if (stacks->a->idx > arr[0] && stacks->a->idx <= arr[1])
		{
			ps_pb(stacks);
			arr[3]++;
		}
		else
		{
			arr[2]++;
		}
	}
}
