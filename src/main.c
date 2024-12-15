/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 03:02:56 by vlow              #+#    #+#             */
/*   Updated: 2024/12/15 19:57:49 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac < 2)
		return (ft_printf("Error\n"));
	if (!chck_arg(av + 1, ac))
		return (ft_printf("Error\n"));
	init_stack(&stacks);
	if (!init_a(&stacks, av + 1, ac))
		return (ft_printf("Error\n"));
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
