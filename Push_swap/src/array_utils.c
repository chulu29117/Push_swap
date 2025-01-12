/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:32:04 by clu               #+#    #+#             */
/*   Updated: 2025/01/11 00:07:29 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copy_stack_to_array(t_stack *stack, int size)
{
	int		*array;
	t_node	*current;
	int		i;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	current = stack->top;
	i = 0;
	while (current)
	{
		array[i++] = current->value;
		current = current->next;
	}
	return (array);
}

static int	partition_array(int *array, int low, int high)
{
	int pivot;
	int i;
	int j;
	int temp;

	pivot = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}
		j++;
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	return (i + 1);
}


void	sort_array(int *array, int low, int high)
{
	int pi;

	while (low < high)
	{
		pi = partition_array(array, low, high);
		sort_array(array, low, pi - 1);
		low = pi + 1;
	}
}

static int	binary_search(int *array, int size, int value)
{
	int low;
	int high;
	int mid;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return (-1);
}

void	norm_indices(t_stack *stack_a, int *array, int size)
{
	t_node	*current;

	current = stack_a->top;
	while (current)
	{
		current->value = binary_search(array, size, current->value);
		current = current->next;
	}
}


// void	sort_array(int *array, int size)
// {
// 	int	i;
// 	int	j;
// 	int	temp;

// 	i = 0;
// 	while (i < size - 1)
// 	{
// 		j = i + 1;
// 		while (j < size)
// 		{
// 			if (array[i] > array[j])
// 			{
// 				temp = array[i];
// 				array[i] = array[j];
// 				array[j] = temp;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

// void	norm_indices(t_stack *stack_a, int *array, int size)
// {
// 	t_node	*current;
// 	int		i;

// 	current = stack_a->top;
// 	while (current)
// 	{
// 		i = 0;
// 		while (i < size)
// 		{
// 			if (current->value == array[i])
// 			{
// 				current->value = i;
// 				break ;
// 			}
// 			i++;
// 		}
// 		current = current->next;
// 	}
// }
