/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:48:41 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 16:41:30 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Free memory and exit with error
void	handle_error(t_stack *stack_a, t_stack *stack_b,
			int *array, t_node *temp_node)
{
	if (temp_node)
		free(temp_node);
	if (array)
		free(array);
	free_stack(&stack_a);
	free_stack(&stack_b);
	exit(EXIT_FAILURE);
}

void	print_error(t_stack *stack_a, t_stack *stack_b,
			int *array, t_node *temp_node)
{
	if (temp_node)
		free(temp_node);
	if (array)
		free(array);
	free_stack(&stack_a);
	free_stack(&stack_b);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}
