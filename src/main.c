/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 03:02:56 by vlow              #+#    #+#             */
/*   Updated: 2024/12/29 02:19:34 by vlow             ###   ########.fr       */
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
		return (0);
	}
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
	op_print_eof(&stacks);
	free_stacks(&stacks);
	return (0);
}

// int	main(void)
// {
// 	t_stacks	stacks;
//
//     char *av[] = {
//         "my_program", // Mimics argv[0] as the program name
//         "68 29 88 75 83 41 51 93 10 7 76 99 85 38 81 35 21 34 43 60 32 55 14 23 96 25 4 11 26 71 78 47 13 46 9 16 2 1 15 59 64 61 67 39 86 73 72 90 95 98 94 84 27 58 91 92 37 36 57 77 33 28 5 42 87 45 63 56 40 100 6 74 48 70 22 79 66 82 44 49 54 30 89 20 8 19 97 50 31 52 62 80 3 12 65 69 18 17 53 24", // Mimics argv[1]
//         NULL // Marks the end of the array
//     };
// 	// if (ac < 2)
// 	// 	return (0);
// 	init_stack(&stacks);
// 	op_init(&stacks);
// 	if (!chck_arg(&stacks, av))
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		return (0);
// 	}
// 	if (!chk_isort(&stacks) || !init_idx(&stacks))
// 	{
// 		free_stacks(&stacks);
// 		return (0);
// 	}
// 	// print_stack(&stacks);
// 	if (stacks.a)
// 	{
// 		ps_init(&stacks);
// 		// print_stack(&stacks);
// 		// ps_pb(&stacks);
// 		// print_stack(&stacks);
// 		// free_stacks(&stacks);
// 		// print_stack(&stacks);
// 	}
// 	// ft_printf("test\n");
// 	// print_stack(&stacks);
// 	op_print_eof(&stacks);
// 	free_stacks(&stacks);
// 	return (0);
// }
