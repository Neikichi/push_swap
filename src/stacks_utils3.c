/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 03:05:23 by vlow              #+#    #+#             */
/*   Updated: 2024/12/15 19:53:01 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>

static int	err_ac(char **str, int ac);
static int	err_nodigit(char *av);

int	chck_arg(char **av, int ac)
{
	char	**temp;

	temp = av;
	if (!av || !*av || !**av)
		return (0);
	while (*temp)
	{
		if (!err_nodigit(*temp))
			return (0);
		temp++;
	}
	if (!chk_split(av, ac))
		return (0);
	return (1);
}

static int	err_nodigit(char *av)
{
	char	*temp;
	int		dg;

	dg = 0;
	temp = av;
	while (*temp)
	{
		if (ft_isalpha(*temp) || *temp == '.')
			return (0);
		if (ft_issign(*temp) && (*(temp + 1) && ft_issign(*(temp + 1))))
			return (0);
		if (ft_isdigit(*temp))
		{
			if (*(temp + 1) && ft_issign(*(temp + 1)))
				return (0);
			dg++;
		}
		temp++;
	}
	if (dg)
		return (1);
	return (0);
}

static int	err_ac(char **str, int ac)
{
	if (!ac)
		free_split(str);
	return (0);
}

int	chk_split(char **str, int ac)
{
	char	**temp;

	temp = str;
	while (*temp)
	{
		if (**temp)
		{
			if (!chk_atoi(*temp))
				return (err_ac(str, ac));
			if (ft_issign(**temp))
			{
				if (!((*temp)[1]) || !ft_isdigit((*temp)[1]))
					return (err_ac(str, ac));
			}
		}
		temp++;
	}
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
