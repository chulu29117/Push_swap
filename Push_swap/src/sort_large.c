/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:11:48 by clu               #+#    #+#             */
/*   Updated: 2025/01/08 12:22:02 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Copy stack values into an array
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

// Sort the array
void	sort_array(int	*array, int size)
{
	
}

// Normalize values in the stack to indices
void	norm_indices(t_stack *stack_a, int *array, int size)
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
				current->value = i;		// replace value with index
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

// Radix sorting method
void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;

	size = stack_a->size;
	max_bits = 0;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack_a->top->value >> i) & 1) == 0)
				pb(stack_a, stack_b);	// push to stack_b if 0
			else
				ra(stack_a);			// rotate stack_a if 1
			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}

