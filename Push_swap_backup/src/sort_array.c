/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:32:04 by clu               #+#    #+#             */
/*   Updated: 2025/01/15 13:02:25 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to sort an array using bubble sort
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

// Function to create an array from stack values and sort it using bubble sort
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
