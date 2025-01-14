/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:11:48 by clu               #+#    #+#             */
/*   Updated: 2025/01/14 11:33:34 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	process_bit(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	count;
	int	size;

	size = stack_a->size;
	count = 0;
	while (count < size)
	{
		if (((stack_a->top->value >> bit) & 1) == 1)
			ra(stack_a);
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

	max_bits = 0;
	while ((stack_a->size - 1) >> max_bits)
		max_bits++;
	bit = 0;
	while (bit < max_bits)
	{
		process_bit(stack_a, stack_b, bit);
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		bit++;
	}
	min_index = find_min_index(stack_a);
	move_min_to_top(stack_a, min_index);
}
