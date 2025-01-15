/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:11:48 by clu               #+#    #+#             */
/*   Updated: 2025/01/15 10:07:22 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int get_max_bits(t_stack *stack)
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
	return max_bits;
}

// Process the current bit of the numbers in the stack
void process_bit(t_stack *stack_a, t_stack *stack_b, int bit_position, int size)
{
	int	j;
	int	pushed;
	int	current;

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
void radix_sort(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	max_bits;
	int	i;

	max_bits = get_max_bits(stack_a);
	i = 0;
	while (i < max_bits)
	{
		process_bit(stack_a, stack_b, i, size);
		i++;
	}
}

// Function for sorting large inputs
void	sort_large(t_stack *stack_a, t_stack *stack_b)
{
	normalize_stack(stack_a, stack_a->size);
	radix_sort(stack_a, stack_b, stack_a->size);
}
