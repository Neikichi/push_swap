/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:39:39 by vlow              #+#    #+#             */
/*   Updated: 2024/12/17 04:18:50 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static int	init_a_h(t_stacks *stacks, char **str, char **temp);
static int	chk_dupes_h(t_stacks *stacks, int *n);

int	chk_dupes(t_stacks *stacks, int *n)
{
	t_list	*temp;
	t_list	*ptr;

	if (chk_dupes_h(stacks, n))
		return (1);
	ptr = stacks->ds;
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

static int	chk_dupes_h(t_stacks *stacks, int *n)
{
    if (!stacks->ds || *(int *)stacks->ds->content > *n)
    {
        ft_lstadd_front(&stacks->ds, ft_lstnew(n));
        return (1);
    }
	return (0);
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

int	init_a(t_stacks *stacks, char *av)
{
	char	**str;
	char	**temp;

	str = ft_split(av, ' ');
	if (!str || !chk_split(str))
		return (0);
	temp = str;
	// split_print(str);
	if (!init_a_h(stacks, str, temp))
		return (0);
	return (1);
}

static int	init_a_h(t_stacks *stacks, char **str, char **temp)
{
	int		*n;

	while (*temp)
	{
		n = malloc(sizeof(int));
		if (!n)
			return (0);
		*n = ft_atoi(*temp);
		if (!chk_dupes(stacks, n))
		{
			free_split(str);
			// free_dupes(stacks);
			return (0);
		}
		ft_lstadd_back(&stacks->a, ft_lstnew(n));
		temp++;
	}
	free_split(str);
	// free_dupes(stacks);
	return (1);
}
