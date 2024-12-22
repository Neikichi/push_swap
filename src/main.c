/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 03:02:56 by vlow              #+#    #+#             */
/*   Updated: 2024/12/21 17:09:15 by vlow             ###   ########.fr       */
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
		return (ft_printf("Error\n"));
	if (!chk_isort(&stacks) || !init_idx(&stacks))
	{
		free_stacks(&stacks);
		return (0);
	}
	// print_stack(&stacks);
	if (stacks.a)
	{
		ps_init(&stacks);
		// print_stack(&stacks);
		// ps_pb(&stacks);
		// print_stack(&stacks);
		// free_stacks(&stacks);
		// print_stack(&stacks);
	}
	// ft_printf("test\n");
	// print_stack(&stacks);
	free_stacks(&stacks);
	return (0);
}
