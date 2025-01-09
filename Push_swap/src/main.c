/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:54:02 by clu               #+#    #+#             */
/*   Updated: 2025/01/08 19:13:48 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Check if already sorted
int	is_sorted(t_stack *stack)
{
	t_node	*current;

	current = stack->top;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

// Calling different algo to sort
static void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	*array;

	if(stack_a->size == 2)
		sort_two(stack_a);
	else if(stack_a->size == 3)
		sort_three(stack_a);
	else if(stack_a->size <= 5)
		sort_four_five(stack_a, stack_b);
	else
	{
		array = copy_stack_to_array(stack_a, stack_a->size);
		if (!array)
        	handle_error(stack_a, stack_b, NULL, NULL);
		sort_array(array, stack_a->size);
		norm_indices(stack_a, array, stack_a->size);
		free(array);
		radix_sort(stack_a, stack_b);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1 || (argc == 2 && !argv[1][0]))
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		handle_error(stack_a, stack_b, NULL, NULL);
	if (argc == 1)
		handle_error(stack_a, stack_b, NULL, NULL);
	if (!parse_input(stack_a, argc, argv))
		handle_error(stack_a, stack_b, NULL, NULL);
	if (is_sorted(stack_a))
		return (free_stack(&stack_a), free_stack(&stack_b), 0);
	sort_stack(stack_a, stack_b);
	if (stack_a)
		free_stack(&stack_a);
	if (stack_b)
		free_stack(&stack_b);
	return (0);
}

