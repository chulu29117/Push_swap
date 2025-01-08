/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:54:02 by clu               #+#    #+#             */
/*   Updated: 2025/01/07 21:43:18 by clu              ###   ########.fr       */
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
		// Call sorting algorithm
		// sort_stack(stack_a, stack_b)
		if(stack_a->size == 2)
			sort_two(stack_a);
		else if(stack_a->size == 3)
			sort_three(stack_a);
		else if(stack_a->size <= 5)
			sort_four_five(stack_a, stack_b);
		else
			radix_sort(stack_a, stack_b);
	}
	print_stack(stack_a, "stack_a");
	// Free memory
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

