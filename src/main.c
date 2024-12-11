#include "libft.h"
#include "push_swap.h"
#include <signal.h>
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

int	chk_stacks(t_list **ds, int *n)
{
	t_list *temp;
	t_list *ptr;

	if (!*ds)
	{
		*ds = ft_lstnew(n);
		return (1);
	}
	if (*(int *)(*ds)->content > *n)
    {
        // temp = ft_lstnew(n);
        // if (!temp)
        //     return (0);
        // temp->next = *ds;
        // *ds = temp;
		ft_lstadd_front(ds, ft_lstnew(n));
        return (1);
    }
	ptr = *ds;
	while (ptr)
	{
		// ft_printf("Traversing: Current content: %d, Checking n: %d\n", *(int *)ptr->content, *n);
		//
		if (*(int *)ptr->content == *n)
		{
			ft_printf("Duplicate found for n: %d\n", *n);
			return (0);
		}
		else if (*(int *)ptr->content < *n && (!ptr->next || *(int *)ptr->next->content > *n))
		{
			// if (!ptr->next)
			// 	ft_printf("Inserting at the end: [%d]\n", *n);
			// else
			// 	ft_printf("Inserting [%d] between [%d] and [%d]\n", *n, *(int *)ptr->content, *(int *)ptr->next->content);
			temp = ft_lstnew(n);
			if (!temp)
				return (0);
			temp->next = ptr->next;
			ptr->next = temp;
			break ;
		}
		else
		{
			ptr = ptr->next;
		}
	}
	return (1);
}

int	init_a(t_stacks *stacks, char *argv)
{// need free function if malloc or lst fail
	char **str;
	char **temp;
	int *n;
	int count;
	t_list *ds;

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
		if (!chk_stacks(&ds, n))
		{
			return (0);		
		}
		ft_lstadd_back(&stacks->a, ft_lstnew(n));
		free(*temp);
		count++;
		temp++;
	}
	ft_printf("Count: %d\n", count);
	print_list(ds);
	free(str);
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

void	free_stacks(t_stacks *stacks)
{
	ft_lstclear(&stacks->a, free);
	ft_lstclear(&stacks->b, free);
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
	// print_stack(&stacks);
	ps_pb(&stacks);
	// print_stack(&stacks);
	free_stacks(&stacks);
	// print_stack(&stacks);
	return (0);
}
