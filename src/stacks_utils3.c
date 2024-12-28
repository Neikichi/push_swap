/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:40:33 by vlow              #+#    #+#             */
/*   Updated: 2024/12/29 02:19:08 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	init_stack(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->ds = NULL;
	stacks->size = 0;
	stacks->ea = NULL;
	stacks->eb = NULL;
	stacks->op.buf_cur = NULL;
	stacks->op.buf_prv = NULL;
}

void	free_stacks(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, free);
	ft_lstclear(&stacks->b, free);
	free_ds(stacks);
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

void	free_ds(t_stacks *stacks)
{
	t_list	*ptr;
	t_list	*temp;

	if (!stacks->ds)
		return ;
	ptr = stacks->ds->next;
	while (ptr)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	free(stacks->ds);
}
