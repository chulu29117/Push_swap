/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 10:12:38 by clu               #+#    #+#             */
/*   Updated: 2025/01/31 14:55:39 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate the stack to bring the value to the top
static void	rotate_stack(t_stack *stack, int count, char stack_name, int rev)
{
	while (count > 0)
	{
		if (rev)
		{
			if (stack_name == 'b')
				rrb(stack);
			else
				rra(stack);
		}
		else
		{
			if (stack_name == 'b')
				rb(stack);
			else
				ra(stack);
		}
		count--;
	}
}

// Rotate the stack to bring the value to the top
static void	rot_to_top(t_stack *stack, int index, char stack_name)
{
	int	size;
	int	count;
	int	rev;

	size = stack->size;
	if (index == 0)
		return ;
	rev = 0;
	if (index > size / 2)
	{
		count = size - index;
		rev = 1;
	}
	else
		count = index;
	rotate_stack(stack, count, stack_name, rev);
}

// Push chunks of values from stack_a to stack_b
// If the value is within the range of min and max, push to stack B
// Otherwise, rotate stack A
static void	push_chunk_to_b(t_stack *a, t_stack *b, int min, int max)
{
	int	size;
	int	j;
	int	top;

	j = 0;
	size = a->size;
	while (j < size)
	{
		top = a->top->value;
		if (top >= min && top <= max)
			pb(a, b);
		else
			ra(a);
		j++;
	}
}

// Process the chunks of values
static void	process_chunks(t_stack *a, t_stack *b, int size, int num_chunks)
{
	int	chunk_size;
	int	min_chunk;
	int	max_chunk;
	int	i;

	chunk_size = size / num_chunks;
	i = 0;
	while (i < num_chunks)
	{
		min_chunk = i * chunk_size;
		if (i == num_chunks - 1)
			max_chunk = size - 1;
		else
			max_chunk = (i + 1) * chunk_size - 1;
		push_chunk_to_b(a, b, min_chunk, max_chunk);
		i++;
	}
}

// Sort the stacks in chunks of 5 values
void	sort_mid(t_stack *stack_a, t_stack *stack_b, int size)
{
	int	max_index;
	int	num_chunks;

	num_chunks = 5;
	process_chunks(stack_a, stack_b, size, num_chunks);
	while (stack_b->size > 0)
	{
		max_index = find_max_index(stack_b);
		rot_to_top(stack_b, max_index, 'b');
		pa(stack_a, stack_b);
	}
}

// // Rotate the stack to bring the value to the top
// // If stack_name is 'b', rotate stack B
// static void	rotate_forward(t_stack *stack, int count, char stack_name)
// {
// 	while (count-- > 0)
// 	{
// 		if (stack_name == 'b')
// 			rb(stack);
// 		else
// 			ra(stack);
// 	}
// }

// // Rotate the stack in reverse to bring the value to the top
// // If stack_name is 'b', reverse rotate stack B
// static void	rotate_reverse(t_stack *stack, int count, char stack_name)
// {
// 	while (count-- > 0)
// 	{
// 		if (stack_name == 'b')
// 			rrb(stack);
// 		else
// 			rra(stack);
// 	}
// }

// // Rotate the stack to bring the value to the top
// // If the index is less than half the size of the stack, rotate forward
// static void	rot_to_top(t_stack *stack, int index, char stack_name)
// {
// 	int	size;
// 	int	count;

// 	size = stack->size;
// 	if (index == 0)
// 		return ;
// 	if (index <= size / 2)
// 		rotate_forward(stack, index, stack_name);
// 	else
// 	{
// 		count = size - index;
// 		rotate_reverse(stack, count, stack_name);
// 	}
// }

// Sort the stacks in chunks of 5 values
// Loop through the chunks and push the chunk to stack B
// Find the max value in stack B and rotate stack B to bring the max to the top
// Push the max value to stack A
// Repeat until stack B is empty
// void	sort_mid(t_stack *stack_a, t_stack *stack_b, int size)
// {
// 	int	chunk_size;
// 	int	max_index;
// 	int	min_chunk;
// 	int	max_chunk;
// 	int	i;
// 	int num_chunks;

// 	num_chunks = 5;
// 	chunk_size = size / num_chunks;
// 	i = 0;
// 	while (i < num_chunks)
// 	{
// 		min_chunk = i * chunk_size;
// 		if (i == num_chunks - 1)
// 			max_chunk = size - 1;
// 		else
// 			max_chunk = (i + 1) * chunk_size - 1;
// 		push_chunk_to_b(stack_a, stack_b, min_chunk, max_chunk);
// 		i++;
// 	}
// 	while (stack_b->size > 0)
// 	{
// 		max_index = find_max_index(stack_b);
// 		rot_to_top(stack_b, max_index, 'b');
// 		pa(stack_a, stack_b);
// 	}
// }
