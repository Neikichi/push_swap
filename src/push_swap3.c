/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 05:06:21 by vlow              #+#    #+#             */
/*   Updated: 2024/12/22 05:12:37 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

// Function prototypes
// void ps_quick_sort(t_stacks *stacks);
void ps_sort_stack_b(t_stacks *stacks);
void partition_stack(t_stacks *stacks, int pivot);
void partition_stack_b(t_stacks *stacks, int pivot);
int calculate_pivot(t_list *stack, int size);
// int ft_lstsize(t_list *stack);
// void rotate_to_top(t_stacks *stacks, int target_idx, char stack_name);
void simple_sort_small_stack(t_stacks *stacks, int size, char stack_name);

// Main quick sort function
void ps_quick_sort(t_stacks *stacks) {
    int size = ft_lstsize(stacks->a);
	if (size <= 3) {
        simple_sort_small_stack(stacks, size, 'a'); // Sort stack a directly
        return;
    }
    int pivot = calculate_pivot(stacks->a, size);

    // Partition stack a around the pivot
    partition_stack(stacks, pivot);

    // Recursively sort the larger partition in stack a
    ps_quick_sort(stacks);

    // Recursively sort the smaller partition in stack b
    ps_sort_stack_b(stacks);

    // Reassemble: Push all elements from stack b back to stack a
    while (ft_lstsize(stacks->b) > 0) {
        ps_pa(stacks);
    }
}

void simple_sort_small_stack(t_stacks *stacks, int size, char stack_name) {
    t_list *stack = (stack_name == 'a') ? stacks->a : stacks->b;

    if (size == 2) {
        // Swap if needed for size 2
        if (stack->idx > stack->next->idx) {
            if (stack_name == 'a') ps_sa(stacks);
            else ps_sb(stacks);
        }
    } else if (size == 3) {
        // Sort for size 3 using swaps and rotations
        if (stack->idx > stack->next->idx && stack->idx > stack->next->next->idx) {
            if (stack_name == 'a') ps_ra(stacks);
            else ps_rb(stacks);
        }
        if (stack->idx > stack->next->idx) {
            if (stack_name == 'a') ps_sa(stacks);
            else ps_sb(stacks);
        }
        if (stack->next->idx > stack->next->next->idx) {
            if (stack_name == 'a') {
                ps_rra(stacks);
                ps_sa(stacks);
            } else {
                ps_rrb(stacks);
                ps_sb(stacks);
            }
        }
    }
}

// Partition stack a around the pivot
void partition_stack(t_stacks *stacks, int pivot) {
    int size = ft_lstsize(stacks->a);
    for (int i = 0; i < size; i++) {
        if (stacks->a->idx < pivot) {
            ps_pb(stacks); // Push smaller elements to stack b
        } else {
            ps_ra(stacks); // Rotate larger elements in stack a
        }
    }
}

// Recursively sort stack b
void ps_sort_stack_b(t_stacks *stacks) {
    int size = ft_lstsize(stacks->b);
    if (size <= 3) {
        simple_sort_small_stack(stacks, size, 'b'); // Sort stack b directly
        return;
	}
    int pivot = calculate_pivot(stacks->b, size);

    // Partition stack b around the pivot
    partition_stack_b(stacks, pivot);

    // Recursively sort both partitions
    ps_sort_stack_b(stacks);
    ps_quick_sort(stacks);
}

// Partition stack b around the pivot
void partition_stack_b(t_stacks *stacks, int pivot) {
    int size = ft_lstsize(stacks->b);
    for (int i = 0; i < size; i++) {
        if (stacks->b->idx < pivot) {
            ps_rb(stacks); // Rotate smaller elements in stack b
        } else {
            ps_pa(stacks); // Push larger elements to stack a
        }
    }
}

// Calculate pivot as the approximate median of the stack
int calculate_pivot(t_list *stack, int size) {
    int sum = 0;
    t_list *current = stack;
    while (current) {
        sum += current->idx;
        current = current->next;
    }
    return sum / size; // Approximate median
}
