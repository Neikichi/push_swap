/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 03:05:23 by vlow              #+#    #+#             */
/*   Updated: 2024/12/14 21:50:27 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <limits.h>

int	chck_arg(char **av, int ac)
{
	char	**temp;
	char	*ptr;

	temp = av;
	if (!av || !*av || !**av)
		return (0);
	while (*temp)
	{
		ptr = *temp;
		while (*ptr)
		{
			if (ac > 2)
				if (ft_isspace(*ptr)
					|| (*(ptr + 1) && ft_issign(*(ptr + 1))))
					return (0);
			if (ft_isalpha(*ptr) || (*(ptr + 1) && ft_issign(*(ptr + 1))))
				return (0);
			ptr++;
		}
		temp++;
	}
	if (!chk_split(av, ac))
		return (0);
	return (1);
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
			{
				if (!ac)
					free_split(str);
				return (0);
			}
			if (ft_issign(**temp))
			{
				if (!((*temp)[1]) || !ft_isdigit((*temp)[1]))
				{
					if (!ac)
						free_split(str);
					return (0);
				}
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
		if ((!neg && amt > INT_MAX) || (neg && -amt < INT_MIN))
			return (0);
		nptr++;
	}
	return (1);
}

void	split_print(char **str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_printf("Split returned NULL.\n");
		return ;
	}
	ft_printf("Split result:\n");
	while (str[i])
	{
		ft_printf("[%d]: %s\n", i, str[i]);
		i++;
	}
	ft_printf("[%d]: %s\n", i, str[i]);
}
