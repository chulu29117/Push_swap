/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:11:48 by clu               #+#    #+#             */
/*   Updated: 2025/01/14 13:04:53 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_chunk_to_b(t_stack *stack_a, t_stack *stack_b, int start, int end)
{
	int	count;

	count = stack_a->size;
	while (count > 0)
	{
		if (stack_a->top->value >= start && stack_a->top->value <= end)
			pb(stack_a, stack_b);
		else if (find_min_index(stack_a) > stack_a->size / 2)
			rra(stack_a);
		else
			ra(stack_a);
		count--;
	}
}

static void	push_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->size > 0)
	{
		move_min_to_top(stack_b, find_min_index(stack_b));
		pa(stack_a, stack_b);
	}
}

void	chunk_sort(t_stack *stack_a, t_stack *stack_b, int chunk_size)
{
	int	start;
	int	end;
	int	max_value;

	max_value = stack_a->size - 1;
	start = 0;
	while (start <= max_value)
	{
		end = start + chunk_size - 1;
		if (end > max_value)
			end = max_value;
		push_chunk_to_b(stack_a, stack_b, start, end);
		push_back_to_a(stack_a, stack_b);
		start += chunk_size;
	}
}

static void	process_bit(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	count;
	int	size;

	size = stack_a->size;
	count = 0;
	while (count < size)
	{
		if (((stack_a->top->value >> bit) & 1) == 1)
		{
			if (stack_b->top && ((stack_b->top->value >> bit) & 1) == 1)
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
		else
			pb(stack_a, stack_b);
		count++;
	}
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	bit;
	int	min_index;

	max_bits = get_max_bits(stack_a);
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(stack_a, stack_b, bit);
		while (stack_b->size != 0)
			pa(stack_a, stack_b);
		bit++;
	}
	min_index = find_min_index(stack_a);
	if (min_index != 0)
		move_min_to_top(stack_a, min_index);
}
