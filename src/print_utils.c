/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:36:46 by vlow              #+#    #+#             */
/*   Updated: 2024/12/18 17:31:05 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// static void	print_idx(t_list *lst);

void	print_stack(t_stacks *stacks)
{
	t_list	*ta;
	t_list	*tb;
	t_list	*ts;
	int		size;

	size = 1;
	ta = stacks->a;
	tb = stacks->b;
	ts = stacks->ds;
	ft_printf("%-19s|%19s|	Ds	| Size: %d\n", "Stacks A", "Stacks B     ", stacks->size);
	while (ta || tb)
	{
		if (ta)
		{
			ft_printf("[%3d]: %-12d", ta->idx, *(int *)ta->content);
			ta = ta->next;
		}
		else
			ft_printf("%-19c", ' ');
		ft_printf("|");
		if (tb)
		{
			ft_printf("[%3d]: %-12d", tb->idx, *(int *)tb->content);
			tb = tb->next;
		}
		else
			ft_printf("%19c", ' ');
		ft_printf("|");
		if (ts)
		{
			ft_printf("uI:%d = %d = i: %d", size++, *(int *)ts->content, ts->idx);
			ts = ts->next;
		}
		else
			ft_printf("%10c", ' ');
		ft_printf("\n");
	}
}

// static void	print_idx(t_list *lst)
// {
// 	ft_printf("[%d]: %-11d", lst->idx, *(int *)lst->content);
// 	lst = lst->next;
// }
//
void	print_ds(t_stacks *stacks)
{
	t_list	*ptr;
	int		count;

	count = 1;
	ptr = stacks->ds;
	ft_printf("Size of arr with dupe and sorted.\n");
	while (ptr)
	{
		ft_printf("Index: %d | Content: %d\n", count++, *(int *)ptr->content);
		ptr = ptr->next;
	}
}

void	split_print(char **str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_printf("Split returned NULL.\n");
		return ;
	}
	ft_printf("Split result:\n");
	while (str[i])
	{
		ft_printf("[%d]: %s\n", i, str[i]);
		i++;
	}
	ft_printf("[%d]: %s\n", i, str[i]);
}
