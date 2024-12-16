/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:40:33 by vlow              #+#    #+#             */
/*   Updated: 2024/12/13 03:06:36 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	print_stack(t_stacks *stacks)
{
	t_list	*ta;
	t_list	*tb;

	ta = stacks->a;
	tb = stacks->b;
	ft_printf("Stack A	|	Stack B\n");
	while (ta || tb)
	{
		if (ta)
		{
			ft_printf("%-10d ", *(int *)ta->content);
			ta = ta->next;
		}
		else
			ft_printf("%-10c", ' ');
		ft_printf("| ");
		if (tb)
		{
			ft_printf("%10d ", *(int *)tb->content);
			tb = tb->next;
		}
		else
			ft_printf("%10c", ' ');
		ft_printf("\n");
	}
}

void	print_list(t_list *ds)
{
	t_list	*ptr;
	int		count;

	count = 1;
	ptr = ds;
	ft_printf("Size of arr with dupe and sorted.\n");
	while (ptr)
	{
		ft_printf("Index: %d | Content: %d\n", count++, *(int *)ptr->content);
		ptr = ptr->next;
	}
}

void	free_stacks(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, free);
	ft_lstclear(&stacks->b, free);
}

void	free_split(char **str)
{
	char	**temp;

	if (!str)
		return ;
	temp = str;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(str);
}

void	free_dupes(t_list *ds)
{
	t_list	*ptr;
	t_list	*temp;

	if (!ds)
		return ;
	ptr = ds->next;
	while (ptr)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	free(ds);
}
