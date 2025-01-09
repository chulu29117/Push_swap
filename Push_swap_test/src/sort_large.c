/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:11:48 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 22:25:52 by clu              ###   ########.fr       */
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
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] > array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
			j++;
		}
		i++;
	}
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
				// ft_printf("Normalizing node with value: %d to index: %d\n", current->value, i);
				current->value = i;		// replace value with index
				break ;
			}
			i++;
		}
		current = current->next;
	}
}

// Radix sorting method
static void	process_bits(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	size;
	int	i;

	size = stack_a->size;
	i = 0;
	while (i < size)
	{
		if (((stack_a->top->value >> bit) & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	i;
	int	max_value;

	if (!stack_a || !stack_b || stack_a->size <= 1)
		return ;
	max_value = stack_a->size - 1;
	max_bits = 0;
	while (max_value >> max_bits != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		process_bits(stack_a, stack_b, i);
		i++;
	}
}
