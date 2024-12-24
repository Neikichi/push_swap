/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:03:44 by vlow              #+#    #+#             */
/*   Updated: 2024/12/24 16:13:26 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>
#include <limits.h>

void	ps_qsa(t_stacks *stacks);
void	ps_qsb(t_stacks *stacks);
int	ft_lstfind(t_list *lst, int target);
int	ft_lstrfind(t_list *lst, int target);
void	qs_try(t_stacks *stacks, int size);
void	qs_tryb(t_stacks *stacks, int size);

void	ps_sort(t_stacks *stacks)
{
	// int cs = stacks->size - (stacks->size / 3 * 2);
	//
	// while (chk_isort(stacks) || stacks->b)
	// {
	// 	int ic = ps_ic(stacks->a->idx, stacks->size);
	//
	// 	if (ft_lstsize(stacks->a) == cs)
	// 		break ;
	// 	if (ic == 1)
	// 	{
	// 		ps_sc(stacks);
	// 		// a function to either swap it big n small
	// 		// then move it to b, do i need to sort it before
	// 		// rotate to bot?
	// 	}
	// 	if (ic == 2)
	// 	{
	// 		ps_mc(stacks);
	// 		// mid chunk, so this have to be small then big
	// 		// then push to top of b. or can just swap there.
	// 	}
	// 	if (ic == 3)
	// 	{
	// 		ps_lc(stacks);
	// 		// basically the biggest range left in a, 
	// 		// to be sorted once mid and small sent to b
	// 	}
	// }
	// ps_qs(stacks);
	// ps_qsb(stacks);
	// ft_printf("|| median: %d\n", find_median(stacks->a, ft_lstsize(stacks->a)));
	qs_try(stacks, stacks->size);
}

void	ps_qs(t_stacks *stacks)
{
	while (ft_lstsize(stacks->a) > 3)
	{
		// if (stacks->a->idx != stacks->size && (stacks->a->idx != stacks->a->next->idx - 1 || stacks->a->idx != stacks->ea->idx + 1))
		int p = find_median(stacks->a, ft_lstsize(stacks->a));
		if (stacks->a->idx < p)
		{
			ps_pb(stacks);
			// ps_qsa(stacks);
		}
		else
			ps_ra(stacks);
	}
	ps_simple_a(stacks);
	// ps_qsb(stacks);
	while (stacks->b)
	{
		ps_qsb(stacks);
		ps_qsa(stacks);
		if (ft_lstfind(stacks->a, stacks->size) < ft_lstrfind(stacks->a, stacks->size))
		{
			while (stacks->ea->idx != stacks->size)
				ps_ra(stacks);
		}
		else
			while (stacks->ea->idx != stacks->size)
				ps_rra(stacks);
		// ps_ra(stacks);
	}
	while (chk_isort(stacks))
	{
		ps_ra(stacks);
	}


	// int p = find_median(stacks->a, ft_lstsize(stacks->a));
	// int cs = ft_lstsize(stacks->a);
	// if (cs <= 3)
	// {
	// 	ps_simple_a(stacks);
	// 	return ;
	// }
	// // int n = stacks->ea->idx;
	// // int p = (cs / 2) + 67;
	// // int i = cs;
	// while (ft_lstsize(stacks->a) > 3)
	// {
	// 	if (stacks->a->idx <= p)
	// 		ps_pb(stacks);
	// 	else
	// 		ps_ra(stacks);
	// }
	// ps_qsb(stacks);
	// ps_qs(stacks);
}

void	qs_try(t_stacks *stacks, int size)
{
	if (size <= 3)
	{
		ps_simple(stacks, 0);
		return ;
	}

	int pivot = find_median(stacks->a, size);
	// ft_printf("p: [%d]\n", pivot);
	int i = 0;
	int ptb = 0;
	int rri = 0;

	while (i++ < size)
	{
		if (stacks->a->idx < pivot)
		{
			// ps_pb(stacks);
			// int ic = ps_ic(stacks->a->idx, size);
			// if (ic == 1)
			// 	ps_sc(stacks);
			// else if (ic == 2)
			// 	ps_mc(stacks);
			// else
			// // 	ps_pb(stacks);
			// ps_simple(stacks, 1);
			if (stacks->b && stacks->a->idx - 1 != stacks->b->idx)
			{
				int xf = ft_lstfind(stacks->b, stacks->a->idx - 1);
				int xr = ft_lstrfind(stacks->b, stacks->a->idx - 1);
				if (xf == -1)
					ps_pb(stacks);
				else if (xf < xr)
				{
					while (stacks->b->idx != stacks->a->idx - 1)
						ps_rb(stacks);
				}
				else
				{
					while (stacks->b->idx != stacks->a->idx - 1)
						ps_rrb(stacks);
				}
			}
			ps_pb(stacks);
			ptb++;
		}
		else
		{
			ps_ra(stacks);
			rri++;
		}
	}
	// while (rri--)
	// 	ps_rra(stacks);
	qs_try(stacks, size - ptb);
	// qs_tryb(stacks, ptb);

	while (ptb--)
	{
		// ps_simple(stacks, 0);
		// ps_simple(stacks, 1);
		if (stacks->a->idx != stacks->b->idx - 1)
		{
			if (ft_lstfind(stacks->b, stacks->a->idx - 1) < ft_lstrfind(stacks->b, stacks->a->idx - 1))
				while (stacks->b->idx != stacks->a->idx - 1)
					ps_rb(stacks);
			else
				while (stacks->b->idx != stacks->a->idx - 1)
					ps_rrb(stacks);
		}
		ps_pa(stacks);
	}
}

void	qs_tryb(t_stacks *stacks, int size)
{
	if (size <= 3)
	{
		ps_simple(stacks, 1);
		return ;
	}

	int pivot = find_median(stacks->b, size);
	// ft_printf("bp: [%d]\n", pivot);
	int i = 0;
	int pta = 0;
	int rri = 0;

	while (i++ < size)
	{
		if (stacks->b->idx < pivot)
		{
			ps_pa(stacks);
			pta++;
		}
		else
		{
			ps_rb(stacks);
			rri++;
		}
	}
	while (rri--)
		ps_rrb(stacks);
	qs_tryb(stacks, size - pta);
	qs_try(stacks, pta);

	while (pta--)
		ps_pb(stacks);
}
//
// void	ps_qsx(t_stacks  *stacks)
// {
// 	int p = stacks->b->idx;
// 	int cs = ps_ic(p, stacks->size);
//
// 	if (cs != 3)
// 		return ;
// 	int ic = ps_ic(stacks->b->idx, stacks->size);
// 	int icn = ps_ic(stacks->b->next->idx, stacks->size);
// 	while (ic == 3 || icn == 3)
// 	{
// 		if (stacks->b->idx <= p)
// 			ps_pa(stacks);
// 		else
// 			ps_rb(stacks);
// 	}
// }

void	ps_qsa(t_stacks *stacks)
{
	while (stacks->b)
	{
		int target = stacks->a->idx - 1;
		// int fdist = ft_lstfind(stacks->a, target);
		// int rdist = ft_lstrfind(stacks->a, target);
		int xfdb = ft_lstfind(stacks->b, target);
		int xrdb = ft_lstrfind(stacks->b, target);

		if (target == stacks->b->idx)
		{
			ps_pa(stacks);
		}
		else if (xfdb == -1)
		{
			// ps_qsb(stacks);
			break ;
			// if (xfdb <= xrdb)
			// 	while (stacks->b->idx != target)
			// 		ps_rb(stacks);
			// else
			// 	while (stacks->b->idx != target)
			// 		ps_rrb(stacks);
		}
		else if (xfdb <= xrdb)
			while (stacks->b->idx != target)
				ps_rb(stacks);
		else
		{
			while (stacks->b->idx != target)
				ps_rrb(stacks);
		}
	}
}

void	ps_qsb(t_stacks *stacks)
{
	while (stacks->b)
	{
		int target = stacks->b->idx + 1;
		int fdist = ft_lstfind(stacks->a, target);
		int rdist = ft_lstrfind(stacks->a, target);
		// int xfdb = ft_lstfind(stacks->b, target);
		// int xrdb = ft_lstrfind(stacks->b, target);

		if (target == stacks->a->idx)
		{
			ps_pa(stacks);
		}
		else if (fdist == -1)
		{
			// ps_qsa(stacks);
			break ;
			// if (xfdb <= xrdb)
			// 	while (stacks->b->idx != target)
			// 		ps_rb(stacks);
			// else
			// 	while (stacks->b->idx != target)
			// 		ps_rrb(stacks);
		}
		else if (fdist <= rdist)
			while (stacks->a->idx != target)
				ps_ra(stacks);
		else
		{
			while (stacks->a->idx != target)
				ps_rra(stacks);
		}
	}
}

int	ft_lstfind(t_list *lst, int target)
{
	int dist = 0;
	while (lst)
	{
		if (lst->idx == target)
			break ;
		lst = lst->next;
		dist++;
	}
	if (!lst)
		return (-1);
	return (dist);
}

int	ft_lstrfind(t_list *lst, int target)
{
	int dist = 0;
	t_list *temp = NULL;
	while (lst)
	{
		if (lst->idx == target)
			temp = lst;
		if (temp)
			dist++;
		lst = lst->next;
	}
	if (!temp)
		return (-1);
	return (dist);
}

void	ps_sc(t_stacks *stacks)
{
	int ic = ps_ic(stacks->a->idx, stacks->size);
	int icn = ps_ic(stacks->a->next->idx, stacks->size);

	if (ic == icn)
	{
		if (stacks->a->idx > stacks->a->next->idx)
			ps_sa(stacks);
	}
	if (stacks->b && ps_ic(stacks->b->idx, stacks->size) == 1)
	{
		if (stacks->a->idx > stacks->b->idx && ft_lstsize(stacks->b) > 1)
			ps_rb(stacks);
	}
	ps_pb(stacks);
	ps_rb(stacks);
}

void	ps_mc(t_stacks *stacks)
{
	int ic = ps_ic(stacks->a->idx, stacks->size);
	int icn = ps_ic(stacks->a->next->idx, stacks->size);

	if (ic == icn)
	{
		if (stacks->a->idx > stacks->a->next->idx)
			ps_sa(stacks);
	}
	if (stacks->b && ps_ic(stacks->b->idx, stacks->size) == 2)
	{
		if (stacks->a->idx < stacks->b->idx && ft_lstsize(stacks->b) > 1)
		{
			ps_rb(stacks);
			ps_pb(stacks);
			ps_rrb(stacks);
		}
		else
			ps_pb(stacks);
	}
	else
		ps_pb(stacks);
}

void	ps_lc(t_stacks *stacks)
{
	int ic = ps_ic(stacks->a->idx, stacks->size);
	int icn = ps_ic(stacks->a->next->idx, stacks->size);

	if (ic == icn)
	{
		if (stacks->a->idx < stacks->a->next->idx)
			ps_sa(stacks);
	}
	ps_ra(stacks);
}

int	ps_ic(int idx, int size)
{
	int chunk_size = size / 3;

	if (idx <= chunk_size)
		return (1);
	else if (idx <= chunk_size * 2)
		return (2);
	else
		return (3);
}
