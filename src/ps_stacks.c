/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:31:18 by vlow              #+#    #+#             */
/*   Updated: 2024/12/15 19:57:09 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	init_stack(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
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
