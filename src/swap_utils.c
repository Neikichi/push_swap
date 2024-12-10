#include "libft.h"
#include "push_swap.h"

void	init_stack(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
}

void	ps_sa(t_stacks *stacks)
{
	t_list *temp;

	if (stacks->a && stacks->a->next)
	{
		temp = stacks->a->next;
		stacks->a->next = temp->next;
		temp->next = stacks->a;
		stacks->a = temp;
		ft_putstr_fd("sa\n", 1);
	}
}

void	ps_sb(t_stacks *stacks)
{
	t_list *temp;

	if (stacks->b && stacks->b->next)
	{
		temp = stacks->b->next;
		stacks->b->next = temp->next;
		temp->next = stacks->b;
		stacks->b = temp;
		ft_putstr_fd("sb\n", 1);
	}
}

void	ps_ss(t_stacks *stacks)
{
	ps_sa(stacks);
	ps_sb(stacks);
	ft_putstr_fd("ss\n", 1);
}

void	ps_pa(t_stacks *stacks)
{
	t_list *temp;

	if (stacks->b)
	{
		temp = stacks->b;
		stacks->b = stacks->b->next;
		temp->next = NULL;
		ft_lstadd_front(&stacks->a, temp);
		ft_putstr_fd("pa\n", 1);
	}
}

void	ps_pb(t_stacks *stacks)
{
	t_list *temp;

	if (stacks->a)
	{
		temp = stacks->a;
		stacks->a = stacks->a->next;
		temp->next = NULL;
		ft_lstadd_front(&stacks->b, temp);
		ft_putstr_fd("pb\n", 1);
	}
}

void	ps_ra(t_stacks *stacks)
{
	t_list *temp;

	if (stacks->a)
	{
		temp = stacks->a;
		stacks->a = stacks->a->next;
		temp->next = NULL;
		ft_lstadd_back(&stacks->a, temp);
		ft_putstr_fd("ra\n", 1);
	}
}

void	ps_rb(t_stacks *stacks)
{
	t_list *temp;

	if (stacks->b)
	{
		temp = stacks->b;
		stacks->b = stacks->b->next;
		temp->next = NULL;
		ft_lstadd_back(&stacks->b, temp);
		ft_putstr_fd("rb\n", 1);
	}
}

void	ps_rr(t_stacks *stacks)
{
	ps_ra(stacks);
	ps_rb(stacks);
	ft_putstr_fd("rr\n", 1);
}

void	ps_rra(t_stacks *stacks)
{
	t_list *temp;
	t_list *prev;

	if (ft_lstsize(stacks->a) > 2)
	{
		temp = stacks->a;
		while (temp->next)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		ft_lstadd_front(&stacks->a, temp);
		ft_putstr_fd("rra\n", 1);
	}
}

void	ps_rrb(t_stacks *stacks)
{
	t_list *temp;
	t_list *prev;

	if (ft_lstsize(stacks->b) > 2)
	{
		temp = stacks->b;
		while (temp->next)
		{
			prev = temp;
			temp = temp->next;
		}
		prev->next = NULL;
		ft_lstadd_front(&stacks->b, temp);
		ft_putstr_fd("rrb\n", 1);
	}
}

void	ps_rrr(t_stacks *stacks)
{
	ps_rra(stacks);
	ps_rrb(stacks);
	ft_putstr_fd("rrr\n", 1);
}
