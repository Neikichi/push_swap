/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 03:05:23 by vlow              #+#    #+#             */
/*   Updated: 2024/12/17 04:20:46 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// static int	err_ac(char **str, int ac);
static int	err_chk(char *av);
// static int	err_achk(char *av);

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
		// str = ft_split(*temp, ' ');
		// if (!str || !chk_split(str, ac))
		// 	return (0);
		// if (ac > 2)
		// 	if (!err_achk(*temp))
		// 		return (0);
		// if (!err_chk(*temp))
		// 	return (0);
		// temp++;
	}
	// if (!chk_split(av, ac))
	// 	return (0);
	return (1);
}

// static int	err_achk(char *av)
// {
// 	char	*temp;
// 	int		flag;
//
// 	temp = av;
// 	flag = 0;
// 	while (*temp)
// 	{
// 		if (ft_isdigit(*temp) || ft_issign(*temp))
// 			flag++;
// 		if (flag && ft_issign(*temp))
// 			return (0);
// 		temp++;
// 	}
// 	return (1);
// }

static int	err_chk(char *av)
{
	char	*temp;
	int		flag;

	flag = 0;
	temp = av;
	while (*temp)
	{
		if (ft_isalpha(*temp) || *temp == '.')
			return (0);
		if (ft_issign(*temp) && (*(temp + 1) && ft_issign(*(temp + 1))))
			return (0);
		if (ft_isdigit(*temp))
			flag++;
		if (flag && ft_issign(*temp))
			return (0);
		// if (ft_isdigit(*temp))
		// {
		// 	if (*(temp + 1) && ft_issign(*(temp + 1)))
		// 		return (0);
		// 	dg++;
		// }
		temp++;
	}
	if (flag)
		return (1);
	return (0);
}

// static int	err_ac(char **str)
// {
// 	if (!ac)
// 		free_split(str);
// 	return (0);
// }

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
				// return (err_ac(str, ac));
			// if (ft_issign(**temp))
			// {
			// 	if (!((*temp)[1]) || !ft_isdigit((*temp)[1]))
			// 		return (err_ac(str, ac));
			// }
		}
		temp++;
	}
	return (1);
}
