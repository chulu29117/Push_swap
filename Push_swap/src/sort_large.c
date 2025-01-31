/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:11:48 by clu               #+#    #+#             */
/*   Updated: 2025/01/31 16:08:29 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Get the maximum number of bits needed to represent the largest number
// Loop through the stack and find the largest number
// Calculate the number of bits needed to represent the largest number
int	get_max_bits(t_stack *stack)
{
	int		max_value;
	int		max_bits;
	t_node	*current;

	max_value = 0;
	max_bits = 0;
	current = stack->top;
	while (current)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	while (max_value >> max_bits)
		max_bits++;
	return (max_bits);
}

// Process the current bit of the numbers in the stack
// Loop through the stack and check if the current bit is set
// If the bit is set, rotate the stack A
// If the bit is not set, push the number to stack B
// Push the numbers back to stack A
static void	process_bit(t_stack *stack_a, t_stack *stack_b, int bit_position)
{
	int	j;
	int	pushed;
	int	current;
	int	size;

	size = stack_a->size;
	j = 0;
	pushed = 0;
	while (j < size)
	{
		current = stack_a->top->value;
		if ((current >> bit_position) & 1)
			ra(stack_a);
		else
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		j++;
	}
	while (pushed-- > 0)
		pa(stack_a, stack_b);
}

// Radix sort algorithm
// Get the max bits representing the largest number in the stack
// Loop through the bits and process each bit
void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	i;

	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		process_bit(stack_a, stack_b, i);
		i++;
	}
}

// Function for sorting large inputs
// Normalize the stack values into a range of [0, size - 1]
// Sort the stack using radix sort
void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	normalize_stack(stack_a, stack_a->size);
	radix_sort(stack_a, stack_b);
}
