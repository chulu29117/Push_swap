/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 21:11:48 by clu               #+#    #+#             */
/*   Updated: 2025/01/11 00:07:52 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_max_bits(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		max_bits;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max = current->value;
	max_bits = 0;
	while (current)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

static void	process_bits(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	j;
	int	size;

	size = stack_a->size;
	j = 0;
	while (j < size)
	{
		if (((stack_a->top->value >> bit) & 1) == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		j++;
	}
}

void radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	*array;
	int	max_bits;
	int	i;

	if (!stack_a || !stack_b || stack_a->size <= 1)
		return ;
	array = copy_stack_to_array(stack_a, stack_a->size); // Copy stack to array
	if (!array)
		return ;
	sort_array(array, 0, stack_a->size - 1); // Sort the array
	norm_indices(stack_a, array, stack_a->size); // Normalize indices
	free(array); // Free the array after use
	max_bits = get_max_bits(stack_a); // Get maximum bits based on indices
	i = 0;
	while (i < max_bits)
	{
		process_bits(stack_a, stack_b, i); // Process each bit
		while (stack_b->size > 0)
			pa(stack_a, stack_b); // Push all elements back to stack_a
		i++;
	}
}


// static void	process_bits(t_stack *stack_a, t_stack *stack_b, int bit)
// {
// 	int	j;
// 	int size;

// 	size = stack_a->size;
// 	j = 0;
// 	while (j < size)
// 	{
// 		if (((stack_a->top->value >> bit) & 1) == 0)
// 			pb(stack_a, stack_b);
// 		else
// 			ra(stack_a);
// 		j++;
// 	}
// }

// void	radix_sort(t_stack *stack_a, t_stack *stack_b)
// {
// 	int	max_bits;
// 	int	i;

// 	if (!stack_a || !stack_b || stack_a->size <= 1)
// 		return ;
// 	max_bits = 0;
// 	while ((stack_a->size - 1) >> max_bits != 0)
// 		max_bits++;
// 	i = 0;
// 	while (i < max_bits)
// 	{
// 		process_bits(stack_a, stack_b, i);
// 		while (stack_b->size > 0)
// 			pa(stack_a, stack_b);
// 		i++;
// 	}
// }

