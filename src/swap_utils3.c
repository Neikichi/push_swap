/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 01:35:29 by vlow              #+#    #+#             */
/*   Updated: 2024/12/13 01:38:40 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ps_rrr(t_stacks *stacks)
{
	ps_rra(stacks);
	ps_rrb(stacks);
	ft_putstr_fd("rrr\n", 1);
}
