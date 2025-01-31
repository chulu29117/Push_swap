/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:54:02 by clu               #+#    #+#             */
/*   Updated: 2025/01/31 10:58:31 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if the stack is sorted in ascending order
// Return 1 if the stack is sorted, 0 otherwise
int	is_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

// Sort the stack using different algorithms based on the size of the stack
// Normalize the stack
// Sort small stacks with 5 or less elements
// Sort medium stacks with 100 or less elements
// Sort large stacks with more than 100 elements
static void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	normalize_stack(stack_a, stack_a->size);
	if (stack_a->size <= 5)
		sort_small(stack_a, stack_b);
	else if (stack_a->size <= 100)
		sort_mid(stack_a, stack_b, stack_a->size);
	else
		sort_large(stack_a, stack_b);
}

// Initialize two stacks
// Check if stacks are initialized successfully
// Parse input arguments
// Check if the stack is already sorted
// Free the stacks if the stack is sorted
// Sort the stack
// Free the stacks
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		put_error(stack_a, stack_b);
	if (!parse_input(stack_a, argc, argv))
		put_error(stack_a, stack_b);
	if (is_sorted(stack_a))
		return (free_stack(&stack_a), free_stack(&stack_b), 0);
	sort_stack(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
