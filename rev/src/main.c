/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 03:02:56 by vlow              #+#    #+#             */
/*   Updated: 2024/12/17 04:36:57 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac < 2)
		return (ft_printf("Error\n"));
	init_stack(&stacks);
	if (!chck_arg(&stacks, av))
		return (ft_printf("Error\n"));
	// if (!init_a(&stacks, av, ac))
	// 	return (ft_printf("Error\n"));
	// print_ds(&stacks);
	print_stack(&stacks);
	if (!chk_isort(&stacks))
	{
		free_stacks(&stacks);
		return (0);
	}
	if (stacks.a)
	{
		// print_stack(&stacks);
		// ps_pb(&stacks);
		// print_stack(&stacks);
		// free_stacks(&stacks);
		// print_stack(&stacks);
	}
	// ft_printf("test\n");
	// print_stack(&stacks);
	// free_stacks(&stacks);
	return (0);
}
