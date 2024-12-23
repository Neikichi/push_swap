/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 21:11:59 by vlow              #+#    #+#             */
/*   Updated: 2024/12/23 17:32:43 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_init(t_stacks *stacks)
{
	if (stacks->size <= 3)
	{
		ps_simple_a(stacks);
	}
	if (stacks->size > 3 && stacks->size <= 10)
	{
		ps_simple_ex(stacks);
	}
	else
	{
		ps_sort(stacks);
	}
}
