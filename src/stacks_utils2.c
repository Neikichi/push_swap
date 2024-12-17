/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 03:05:23 by vlow              #+#    #+#             */
/*   Updated: 2024/12/17 21:19:54 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>

static int	err_chk(char *av);

int	chck_arg(t_stacks *stacks, char **av)
{
	char	**temp;

	temp = av;
	if (!av || !*av || !**av)
		return (0);
	while (*(++temp))
	{
		if (!init_a(stacks, *temp))
			return (0);
	}
	return (1);
}

static int	err_chk(char *av)
{
	char	*temp;
	int		flag;

	flag = 0;
	temp = av;
	while (*temp)
	{
		if (!ft_isdigit(*temp) && !ft_issign(*temp))
			return (0);
		if (ft_issign(*temp) && (*(temp + 1) && ft_issign(*(temp + 1))))
			return (0);
		if (ft_isdigit(*temp))
			flag++;
		if (flag && ft_issign(*temp))
			return (0);
		temp++;
	}
	if (flag)
		return (1);
	return (0);
}

int	chk_split(char **str)
{
	char	**temp;

	if (!str || !*str || !**str)
		return (0);
	temp = str;
	while (*temp)
	{
		if (**temp)
		{
			if (!err_chk(*temp) || !chk_atoi(*temp))
			{
				free_split(str);
				return (0);
			}
		}
		temp++;
	}
	return (1);
}

int	init_idx(t_stacks *stacks)
{
	t_list	*ta;
	t_list	*ts;
	int		idx;

	if (!stacks || !stacks->a || !stacks->ds)
		return (0);
	ts = stacks->ds;
	idx = 1;
	while (ts)
	{
		ta = stacks->a;
		while (ta)
		{
			if (*(int *)ts->content == *(int *)ta->content)
			{
				ta->idx = idx++;
				break ;
			}
			ta = ta->next;
		}
		ts = ts->next;
	}
	stacks->size = idx - 1;
	return (1);
}

int	chk_atoi(const char *nptr)
{
	int			neg;
	long int	amt;

	amt = 0;
	neg = 0;
	while (ft_isspace(*nptr))
	{
		nptr++;
	}
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = 1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		amt = amt * 10 + (*nptr - '0');
		if ((!neg && (amt > INT_MAX)) || (neg && (-amt < INT_MIN)))
			return (0);
		nptr++;
	}
	return (1);
}
