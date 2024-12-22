/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:54:02 by clu               #+#    #+#             */
/*   Updated: 2024/12/22 16:23:08 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack();
	stack_b = init_stack();

	if (argc > 1)
	{
		if (!parse_input(stack_a, argc, argv))
		{
			ft_printf("Error\n");
			free_stack(stack_a);
			free_stack(stack_b);
			return (1);
		}
	}
	
	// Print initial stacks for debugging
	ft_printf("Initial Stack A:\n");
	print_stack(stack_a, "A");
	ft_printf("Initial Stack B:\n");
	print_stack(stack_b, "B");

	// Call sorting algorithm
	// sort_stack(stack_a, stack_b)

	// Free memory
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

