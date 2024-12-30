/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 17:36:46 by vlow              #+#    #+#             */
/*   Updated: 2024/12/31 00:42:27 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	print_stack_h(t_list **lst);

void	print_stack(t_stacks *stacks)
{
	t_list	*ta;
	t_list	*tb;

	ta = stacks->a;
	tb = stacks->b;
	ft_printf("%-19s|%-19s| Size: %d\n", "Stacks A", "Stacks B", stacks->size);
	while (ta || tb)
	{
		print_stack_h(&ta);
		ft_printf("|");
		print_stack_h(&tb);
		ft_printf("|");
		ft_printf("\n");
	}
}

static void	print_stack_h(t_list **lst)
{
	if (*lst)
	{
		ft_printf("[%3d]: %-12d", (*lst)->idx, *(int *)(*lst)->content);
		*lst = (*lst)->next;
	}
	else
	{
		ft_printf("%-19c", ' ');
	}
}

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
