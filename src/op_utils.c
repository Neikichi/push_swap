/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:16:20 by vlow              #+#    #+#             */
/*   Updated: 2024/12/29 03:10:05 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	op_init(t_stacks *stacks)
{
	stacks->op.buf_prv = NULL;
	stacks->op.buf_cur = NULL;
}

void	op_ins(t_stacks *stacks, char *str)
{
	char	*dup;

	dup = ft_strdup(str);
	if (!dup)
		return ;
	if (!stacks->op.buf_prv && !stacks->op.buf_cur)
	{
		stacks->op.buf_cur = dup;
	}
	else if (!stacks->op.buf_prv)
	{
		stacks->op.buf_prv = stacks->op.buf_cur;
		stacks->op.buf_cur = dup;
	}
	else
	{
		free(stacks->op.buf_prv);
		stacks->op.buf_prv = stacks->op.buf_cur;
		stacks->op.buf_cur = dup;
	}
	op_print(stacks);
}
