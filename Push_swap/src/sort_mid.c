/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:12:38 by clu               #+#    #+#             */
/*   Updated: 2025/01/15 11:37:48 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate the stack to bring the value to the top
static void	rotate_forward(t_stack *stack, int count, char stack_name)
{
	while (count-- > 0)
	{
		if (stack_name == 'b')
			rb(stack);
		else
			ra(stack);
	}
}

// Rotate the stack in reverse to bring the value to the top
static void	rotate_reverse(t_stack *stack, int count, char stack_name)
{
	while (count-- > 0)
	{
		if (stack_name == 'b')
			rrb(stack);
		else
			rra(stack);
	}
}

// Rotate the stack to bring the value to the top
static void	rot_to_top(t_stack *stack, int index, char stack_name)
{
	int	size;
	int	count;
	
	size = stack->size;
	if (index == 0)
		return ;
	if (index <= size / 2)
		rotate_forward(stack, index, stack_name);
	else
	{
		count = size - index;
		rotate_reverse(stack, count, stack_name);
	}
}

// Push chunks of values from stack_a to stack_b
static void	push_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int min_chunk, int max_chunk)
{
	int	size;
	int	j = 0;
	int	top;

	size = stack_a->size;
	while (j < size)
	{
		top = stack_a->top->value;
		if (top >= min_chunk && top <= max_chunk)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		j++;
	}
}

// Sort the stacks in chunks of 5 for input size less than 100
void	sort_mid(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	chunk_size;
	int	max_index;
	int	min_chunk;
	int	max_chunk;
	int	i;

	chunk_size = size / 5;
	i = 0;
	while (i < 5)
	{
		min_chunk = i * chunk_size;
		max_chunk = (i + 1) * chunk_size - 1;
		push_chunk_to_b(stack_a, stack_b, min_chunk, max_chunk);
		i++;
	}
	while (stack_b->size > 0)
	{
		max_index = find_max_index(stack_b);
		rot_to_top(stack_b, max_index, 'b');
		pa(stack_a, stack_b);
	}
}
