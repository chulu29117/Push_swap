/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:32:04 by clu               #+#    #+#             */
/*   Updated: 2025/01/13 22:16:17 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// partition:
// Selects a pivot (the last element in the range).
// Rearranges the array so that elements smaller than the pivot are on its left, and larger elements are on its right.
int	partition(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
		{
			i++;
			ft_swap(&array[i], &array[j]);
		}
		j++;
	}
	ft_swap(&array[i + 1], &array[high]);
	return (i + 1);
}

// Recursively sorts the partitions created by the partition function.
void	quicksort(int *array, int low, int high)
{
	int	pivot_index;
	
	if (low < high)
	{
		pivot_index = partition(array, low, high);
		quicksort(array, low, pivot_index - 1);
		quicksort(array, pivot_index + 1, high);
	}
}

static void	partition_stack(t_stack *stack_a, t_stack *stack_b, int pivot)
{
	t_node	*current;
	int		size;
	int		i;

	size = stack_a->size;
	i = 0;
	while (i < size)
	{
		current = stack_a->top;
		if (current->value < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

static int	find_median(t_stack *stack)
{
	t_node	*current;
	int		*values;
	int		i;
	int		median;

	values = malloc(sizeof(int) * stack->size);
	if (!values)
		return (-1);
	current = stack->top;
	i = 0;
	while (current)
	{
		values[i++] = current->value;
		current = current->next;
	}
	quicksort(values, 0, stack->size - 1);
	median = values[stack->size / 2];
	free(values);
	return (median);
}

void	quick_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	median;

	median = find_median(stack_a);
	partition_stack(stack_a, stack_b, median);
	quick_sort(stack_a, stack_b);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
