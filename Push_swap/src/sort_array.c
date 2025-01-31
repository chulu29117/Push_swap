/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:32:04 by clu               #+#    #+#             */
/*   Updated: 2025/01/31 16:07:39 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to sort an array using bubble sort
// Loop through the array and swap elements if they are in the wrong order
// If no swaps are made, the array is sorted
static void	bubble_sort(int *array, int size)
{
	int	i;
	int	j;
	int	temp;
	int	swapped;

	i = 0;
	while (i < size - 1)
	{
		swapped = 0;
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				swapped = 1;
			}
			j++;
		}
		if (!swapped)
			break ;
		i++;
	}
}

// Create an array from stack values and sort it using bubble sort
// Return the sorted array
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
	bubble_sort(array, size);
	return (array);
}

// Assign normalized values to the stack based on sorted order
// Assign the index of the value in the sorted array to the stack value
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
// Create an array from stack values and sort it
void	normalize_stack(t_stack *stack, int size)
{
	int	*array;

	array = create_array(stack, size);
	if (!array)
		return ;
	assign_values(stack, array, size);
	free(array);
}
