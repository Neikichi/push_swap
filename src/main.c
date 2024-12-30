/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 03:02:56 by vlow              #+#    #+#             */
/*   Updated: 2024/12/31 01:03:33 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac < 2)
		return (0);
	init_stack(&stacks);
	if (!chck_arg(&stacks, av))
	{
		ft_putstr_fd("Error\n", 2);
		free_stacks(&stacks);
		return (0);
	}
	if (!chk_isort(&stacks) || !init_idx(&stacks))
	{
		free_stacks(&stacks);
		return (0);
	}
	if (stacks.a)
		ps_init(&stacks);
	op_print_eof(&stacks);
	free_stacks(&stacks);
	return (0);
}
