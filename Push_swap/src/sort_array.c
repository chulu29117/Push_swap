/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:32:04 by clu               #+#    #+#             */
/*   Updated: 2025/01/14 22:16:38 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sorts an array of integers using the Quicksort algorithm
static void	quicksort(int *array, int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	if (low >= high)
		return ;
	pivot = array[low];
	i = low;
	j = high;
	while (i < j)
	{
		while (array[j] > pivot)
			j--;
		while (i < j && array[i] <= pivot)
			i++;
		if (i < j)
			ft_swap(&array[i], &array[j]);
	}
	array[low] = array[j];
	array[j] = pivot;
	quicksort(array, low, j - 1);
	quicksort(array, j + 1, high);
}

// Function to create an array from stack values and sort it using quicksort
static int	*create_array(t_stack *stack, int size)
{
	t_node	*current;
	int		*array;
	int		i;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	current = stack->top;
	i = 0;
	while (i < size)
	{
		array[i++] = current->value;
		current = current->next;
	}
	quicksort(array, 0, size - 1);
	return (array);
}

// Function to assign normalized values to the stack based on sorted order
static void	assign_values(t_stack *stack, int *array, int size)
{
	t_node	*current;
	int		i;

	current = stack->top;
	while (current)
	{
		i = 0;
		while (i < size)
		{
			if (current->value == array[i])
			{
				current->value = i;
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

// Normalizes the stack values into a range of [0, size - 1]
void	normalize_stack(t_stack *stack, int size)
{
	int	*array;

	array = create_array(stack, size);
	if (!array)
		return ;
	assign_values(stack, array, size);
	free(array);
}
