/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:32:04 by clu               #+#    #+#             */
/*   Updated: 2025/01/14 11:06:46 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	*create_array(t_stack *stack_a, int size)
{
	t_node	*current;
	int		*array;
	int		i;

	array = malloc(sizeof(int) * size);
	if (!array)
		return (NULL);
	current = stack_a->top;
	i = 0;
	while (current)
	{
		array[i++] = current->value;
		current = current->next;
	}
	quicksort(array, 0, size - 1);
	return (array);
}

static void	assign_values(t_stack *stack_a, int *array, int size)
{
	t_node	*current;
	int		i;

	current = stack_a->top;
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

void	normalize_stack(t_stack *stack_a, int size)
{
	int	*array;

	array = create_array(stack_a, size);
	if (!array)
		return ;
	assign_values(stack_a, array, size);
	free(array);
}