/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 21:43:46 by vlow              #+#    #+#             */
/*   Updated: 2024/12/31 00:46:07 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"
#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static int	check_op(t_stacks *stacks, char *line, int size);
static int	check_op_h(t_stacks *stacks, char *line, int size);
static int	load_moves(t_stacks *stacks);

int	main(int ac, char **av)
{
	t_stacks	stacks;

	if (ac < 2)
		return (0);
	init_stack(&stacks);
	if (!chck_arg(&stacks, av) || !load_moves(&stacks))
	{
		ft_putstr_fd("Error\n", 2);
		free_stacks(&stacks);
		return (0);
	}
	if (chk_isort(&stacks))
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	free_stacks(&stacks);
	return (0);
}

static int	load_moves(t_stacks *stacks)
{
	char	*line;
	int		size;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		size = (int)ft_strlen(line);
		if (!check_op(stacks, line, size))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

static int	check_op(t_stacks *stacks, char *line, int size)
{
	if (!ft_strncmp("sa\n", line, size))
		b_sa(stacks);
	else if (!ft_strncmp("sb\n", line, size))
		b_sb(stacks);
	else if (!ft_strncmp("pa\n", line, size))
		b_pa(stacks);
	else if (!ft_strncmp("pb\n", line, size))
		b_pb(stacks);
	else if (!ft_strncmp("ra\n", line, size))
		b_ra(stacks);
	else if (!ft_strncmp("rb\n", line, size))
		b_rb(stacks);
	else if (!ft_strncmp("rra\n", line, size))
		b_rra(stacks);
	else if (!ft_strncmp("rrb\n", line, size))
		b_rrb(stacks);
	else
		if (!check_op_h(stacks, line, size))
			return (0);
	return (1);
}

static int	check_op_h(t_stacks *stacks, char *line, int size)
{
	if (!ft_strncmp("ss\n", line, size))
	{
		b_sa(stacks);
		b_sb(stacks);
	}
	else if (!ft_strncmp("rr\n", line, size))
	{
		b_ra(stacks);
		b_rb(stacks);
	}
	else if (!ft_strncmp("rrr\n", line, size))
	{
		b_rra(stacks);
		b_rrb(stacks);
	}
	else
		return (0);
	return (1);
}
