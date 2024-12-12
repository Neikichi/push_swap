/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:39:39 by vlow              #+#    #+#             */
/*   Updated: 2024/12/13 03:43:41 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	chk_dupes_h(t_list **ds, int *n)
{
	if (!*ds || *(int *)(*ds)->content > *n)
	{
		ft_lstadd_front(ds, ft_lstnew(n));
		return (1);
	}
	return (0);
}

int	chk_dupes(t_list **ds, int *n)
{
	t_list	*temp;
	t_list	*ptr;

	if (chk_dupes_h(ds, n))
		return (1);
	ptr = *ds;
	while (ptr)
	{
		if (*(int *)ptr->content == *n)
			return (0);
		else if (*(int *)ptr->content < *n
			&& (!ptr->next || *(int *)ptr->next->content > *n))
		{
			temp = ft_lstnew(n);
			if (!temp)
				return (0);
			temp->next = ptr->next;
			ptr->next = temp;
			break ;
		}
		else
			ptr = ptr->next;
	}
	return (1);
}

int	chk_isort(t_stacks *stacks)
{
	t_list	*ta;

	if (!stacks || !stacks->a)
		return (0);
	ta = stacks->a;
	while (ta && ta->next)
	{
		if (*(int *)ta->content > *(int *)ta->next->content)
			return (1);
		ta = ta->next;
	}
	return (0);
}

int	init_a(t_stacks *stacks, char *argv)
{
	char	**str;
	char	**temp;
	int		*n;
	t_list	*ds;

	str = ft_split(argv, ' ');
	if (!str)
		return (0);
	temp = str;
	ds = NULL;
	while (*temp)
	{
		n = malloc(sizeof(int));
		if (!n)
			return (0);
		*n = ft_atoi(*temp);
		if (!chk_dupes(&ds, n))
		{
			free_split(str);
			free_dupes(ds);
			return (0);
		}
		ft_lstadd_back(&stacks->a, ft_lstnew(n));
		temp++;
	}
	free_split(str);
	free_dupes(ds);
	return (1);
}
