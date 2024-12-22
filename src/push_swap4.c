/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlow <vlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 15:44:04 by vlow              #+#    #+#             */
/*   Updated: 2024/12/22 15:50:58 by vlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdlib.h> // Required for malloc and qsort

int find_median(t_list *s, int count) {
    if (!s || count <= 0)
        return 0; // or handle error appropriately

    int *arr = malloc(sizeof(int) * count);
    if (!arr)
        return 0; // or handle allocation failure

    t_list *tmp = s;
    for (int i = 0; i < count; i++) {
        arr[i] = tmp->idx;
        tmp = tmp->next;
    }

    // Use qsort to sort the array
    quicksort(arr, 0, count - 1);

    int pivot = arr[count / 2]; // Median value
    free(arr);
    return pivot;
}

// Swap two integers
static void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition the array
static int partition(int *arr, int low, int high) {
    int pivot = arr[high]; // Pivot is the last element
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]); // Place pivot in correct position
    return i + 1;
}

// Quick Sort function
void quicksort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // Partition index

        quicksort(arr, low, pi - 1);  // Sort the left part
        quicksort(arr, pi + 1, high); // Sort the right part
    }
}
