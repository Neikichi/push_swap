/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:44:04 by vlow              #+#    #+#             */
/*   Updated: 2024/12/28 22:11:37 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static void	swap(int *a, int *b);
static int	partition(int *arr, int low, int high);

int find_pivot(t_list *s, int count, int flag)
{
	int		*arr;
	t_list	*tmp;
	int		i;

    if (!s || count <= 0)
		return 0;
	arr = malloc(sizeof(int) * count);
    if (!arr)
        return (0);
    tmp = s;
	i = 0;
	while (i < count)
	{
		arr[i] = tmp->idx;
		tmp = tmp->next;
		i++;
	}
    quicksort(arr, 0, count - 1);

    // Calculate the pivots
    int first_pivot_idx = count / 3;
    int second_pivot_idx = (count / 3) * 2;

    // Handle edge cases where count is not perfectly divisible by 3
    if (first_pivot_idx >= count)
        first_pivot_idx = count - 1;
    if (second_pivot_idx >= count)
        second_pivot_idx = count - 1;

    int pivot = arr[first_pivot_idx];  // First third pivot
    int px2 = arr[second_pivot_idx];  // Second third pivot

    free(arr);

    // Return the appropriate pivot based on the flag
    return flag ? px2 : pivot;
}


int	find_median(t_list *s, int count)
{
	int		*arr;
	t_list	*tmp;
	int		i;

	if (!s || count <= 0)
		return 0;

	arr = malloc(sizeof(int) * count);
    if (!arr)
        return 0;
    tmp = s;
	i = 0;
	while (i < count)
	{
		arr[i] = tmp->idx;
		tmp = tmp->next;
		i++;
	}
    quicksort(arr, 0, count - 1);
    i = arr[count / 3];
    free(arr);
    return i;
}

void	quicksort(int *arr, int low, int high)
{
	int pi;

    if (low < high)
	{
        pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

static void	swap(int *a, int *b)
{
    int	temp;

	temp = *a;
    *a = *b;
    *b = temp;
}

static int	partition(int *arr, int low, int high)
{
    int pivot;
    int i;
	int j;

	pivot = arr[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
