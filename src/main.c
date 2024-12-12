#include "libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

void print_stack(t_stacks *stacks)
{
    t_list *ta = stacks->a;
    t_list *tb = stacks->b;

	ft_printf("Stack A    |    Stack B\n");
    while (ta || tb)
    {
        if (ta)
        {
            ft_printf("%-10d ", *(int *)ta->content);
            ta = ta->next;
        }
        else
            ft_printf("%-10c", ' ');
        ft_printf("| ");
        if (tb)
        {
            ft_printf("%10d ", *(int *)tb->content);
            tb = tb->next;
        }
        else
            ft_printf("%10c", ' ');
        ft_printf("\n");
    }
}

void	print_list(t_list *ds)
{
	t_list *ptr;
	int		count;

	count = 1;
	ptr = ds;
	ft_printf("Size of arr with dupe and sorted.\n");
	while (ptr)
	{
		ft_printf("Index: %d | Content: %d\n", count++, *(int *)ptr->content);
		ptr = ptr->next;
	}
}

void	free_stacks(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, free);
	ft_lstclear(&stacks->b, free);
}

void	free_split(char **str)
{
	char **temp;

	if (!str)
		return ;
	temp = str;
	while (*temp)
	{
		free(*temp);
		temp++;
	}
	free(str);
}

void	free_dupes(t_list *ds)
{
	t_list  *ptr;
	t_list	*temp;

	if (!ds)
		return ;
	ptr = ds->next;
	while (ptr)
	{
		temp = ptr->next;
		free(ptr);
		ptr = temp;
	}
	free(ds);
}

int	chk_dupes(t_list **ds, int *n)
{
	t_list *temp;
	t_list *ptr;

	if (!*ds || *(int *)(*ds)->content > *n)
    {
		ft_lstadd_front(ds, ft_lstnew(n));
        return (1);
    }
	ptr = *ds;
	while (ptr)
	{
		if (*(int *)ptr->content == *n)
			return (0);
		else if (*(int *)ptr->content < *n && (!ptr->next || *(int *)ptr->next->content > *n))
		{
			temp = ft_lstnew(n);
			if (!temp)
				return (0);
			temp->next = ptr->next;
			ptr->next = temp;
			break ;
		}
		else
			ptr = ptr->next;
	}
	return (1);
}

int	chk_isort(t_stacks *stacks)
{
	t_list *ta;

	if (!stacks || !stacks->a)
		return (0);
	ta = stacks->a;
	while (ta && ta->next)
	{
		if (*(int *)ta->content > *(int *)ta->next->content)
			return (1);
		ta = ta->next;
	}
	return (0);
}

int	init_a(t_stacks *stacks, char *argv)
{// need free function if malloc or lst fail
	char **str;
	char **temp;
	int *n;
	int count;
	t_list *ds;
	int np;
	int sort = 0;

	str = ft_split(argv, ' ');
	if (!str)
		return (0);
	temp = str;
	count = 0;
	ds = NULL;
	while (*temp)
	{
		n = malloc(sizeof(int));
		if (!n)
			return (0);
		*n = ft_atoi(*temp);
		if (!count || np < *n)
			np = *n;
		else
		{
			np = *n;
			sort++;
		}
		if (!chk_dupes(&ds, n))
		{
			free_split(str);
			ft_lstclear(&ds, free);
			return (0);		
		}
		ft_lstadd_back(&stacks->a, ft_lstnew(n));
		count++;
		temp++;
	}
	ft_printf("Count: %d | Sort: %s\n", count, !sort ? "Yes":"No");
	print_list(ds);
	free_split(str);
	free_dupes(ds);
	// free(ds->next->next);
	// free(ds->next);
	// free(ds);
	// ft_lstclear(&ds, free);
	if (sort)
		free_stacks(stacks);
	return (1);
}

int	chck_arg(char *str)
{
	while (*str)
	{
		if (ft_isalpha(*str))
			return (0);
		str++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks stacks;

	if (argc != 2)
		return ft_printf("Error\n");
	if (!chck_arg(argv[1]))
		return ft_printf("Error\n");
	init_stack(&stacks);
	if (!init_a(&stacks, argv[1]))
		return ft_printf("Error\n");
	if (!chk_isort(&stacks))
	{
		free_stacks(&stacks);
		return (0);
	}
	if (stacks.a)
	{
		// print_stack(&stacks);
		ps_pb(&stacks);
		// print_stack(&stacks);
		free_stacks(&stacks);
		// print_stack(&stacks);
	}
	ft_printf("test\n");
	print_stack(&stacks);
	// free_stacks(&stacks);
	return (0);
}
