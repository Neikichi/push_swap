#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	init_a(t_stacks *stacks, char *argv)
{
	char **str;
	int *n;

	str = ft_split(argv, ' ');
	if (!str)
		return (0);
	n = malloc(sizeof(int));
	if (!n)
		return (0);
	while (*str)
	{
		*n = ft_atoi(*str);
		ft_lstadd_front(&stacks->a, ft_lstnew(n));
		free(*str);
		str++;
	}
	free(str);
	return (1);
}

int	chck_arg(char *str)
{
	while (*str)
	{
		if (!ft_isalpha(*str))
			return (1);
		str++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks stacks;

	if (argc != 2)
		return ft_printf("Error\n");
	if (!chck_arg(*argv))
		return ft_printf("Error\n");
	init_stack(&stacks);
	if (!init_a(&stacks, *argv))
		return ft_printf("Error\n");


	return (0);
}
