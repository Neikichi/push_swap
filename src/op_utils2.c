/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 01:35:21 by vlow              #+#    #+#             */
/*   Updated: 2024/12/30 21:17:52 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static int	op_ss(t_stacks *stacks);
static int	op_rr(t_stacks *stacks);
static int	op_rrr(t_stacks *stacks);

void	op_print(t_stacks *stacks)
{
	if (!stacks->op.buf_prv || !stacks->op.buf_cur)
		return ;
	if (op_ss(stacks) || op_rr(stacks) || op_rrr(stacks))
	{
		free(stacks->op.buf_prv);
		free(stacks->op.buf_cur);
		op_init(stacks);
	}
	else
	{
		ft_printf("%s\n", stacks->op.buf_prv);
		free(stacks->op.buf_prv);
		stacks->op.buf_prv = NULL;
	}
}

void	op_print_eof(t_stacks *stacks)
{
	if (!stacks->op.buf_cur && !stacks->op.buf_prv)
		return ;
	if (!stacks->op.buf_prv)
	{
		ft_printf("%s\n", stacks->op.buf_cur);
		free(stacks->op.buf_cur);
		stacks->op.buf_cur = NULL;
	}
	else
	{
		ft_printf("%s\n", stacks->op.buf_prv);
		ft_printf("%s\n", stacks->op.buf_cur);
		free(stacks->op.buf_prv);
		free(stacks->op.buf_cur);
		op_init(stacks);
	}
}

static int	op_ss(t_stacks *stacks)
{
	int	ap;
	int	bp;
	int	ac;
	int	bc;

	ap = ft_strncmp("sa", stacks->op.buf_prv, 2);
	bp = ft_strncmp("sb", stacks->op.buf_prv, 2);
	ac = ft_strncmp("sa", stacks->op.buf_cur, 2);
	bc = ft_strncmp("sb", stacks->op.buf_cur, 2);
	if (!ap && !bc)
	{
		ft_printf("ss\n");
		return (1);
	}
	else if (!bp && !ac)
	{
		ft_printf("ss\n");
		return (1);
	}
	return (0);
}

static int	op_rr(t_stacks *stacks)
{
	int	ap;
	int	bp;
	int	ac;
	int	bc;

	ap = ft_strncmp("ra", stacks->op.buf_prv, 2);
	bp = ft_strncmp("rb", stacks->op.buf_prv, 2);
	ac = ft_strncmp("ra", stacks->op.buf_cur, 2);
	bc = ft_strncmp("rb", stacks->op.buf_cur, 2);
	if (!ap && !bc)
	{
		ft_printf("rr\n");
		return (1);
	}
	else if (!bp && !ac)
	{
		ft_printf("rr\n");
		return (1);
	}
	return (0);
}

static int	op_rrr(t_stacks *stacks)
{
	int	ap;
	int	bp;
	int	ac;
	int	bc;

	ap = ft_strncmp("rra", stacks->op.buf_prv, 3);
	bp = ft_strncmp("rrb", stacks->op.buf_prv, 3);
	ac = ft_strncmp("rra", stacks->op.buf_cur, 3);
	bc = ft_strncmp("rrb", stacks->op.buf_cur, 3);
	if (!ap && !bc)
	{
		ft_printf("rrr\n");
		return (1);
	}
	else if (!bp && !ac)
	{
		ft_printf("rrr\n");
		return (1);
	}
	return (0);
}
