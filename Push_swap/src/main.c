/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:54:02 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 12:13:42 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		radix_sort(stack_a, stack_b);
		print_stack(stack_a, "Stack_a", array);
		free(array);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc <= 1)
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
		return (ft_printf("Stack is already sorted.\n"), free_stack(&stack_a), free_stack(&stack_b), 0);
	sort_stack(stack_a, stack_b);
	if (stack_a)
		free_stack(&stack_a);
	if (stack_b)
		free_stack(&stack_b);
	return (0);
}

