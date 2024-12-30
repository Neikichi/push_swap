/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:44:04 by vlow              #+#    #+#             */
/*   Updated: 2024/12/29 20:10:08 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

static void	swap(int *a, int *b);
static int	partition(int *arr, int low, int high);
static int	find_pivot_h(int *arr, int count, int flag);

int	find_pivot(t_list *s, int count, int flag)
{
	int		*arr;
	t_list	*tmp;
	int		i;

	if (!s || count <= 0)
		return (-1);
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (-1);
	tmp = s;
	i = 0;
	while (i < count)
	{
		arr[i] = tmp->idx;
		tmp = tmp->next;
		i++;
	}
	quicksort(arr, 0, count - 1);
	return (find_pivot_h(arr, count, flag));
}

static int	find_pivot_h(int *arr, int count, int flag)
{
	int	pvt1;
	int	pvt2;
	int	pvt_i1;
	int	pvt_i2;

	pvt_i1 = count / 3;
	pvt_i2 = pvt_i1 * 2;
	if (pvt_i1 >= count)
		pvt_i1 = count - 1;
	if (pvt_i2 >= count)
		pvt_i2 = count - 1;
	pvt1 = arr[pvt_i1];
	pvt2 = arr[pvt_i2];
	free(arr);
	if (flag)
		return (pvt2);
	return (pvt1);
}

void	quicksort(int *arr, int low, int high)
{
	int	pi;

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
	int	pivot;
	int	i;
	int	j;

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
	return (i + 1);
}
