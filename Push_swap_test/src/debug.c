/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:49:24 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 11:17:10 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	print_stack(t_stack *stack, char *name, int *sorted_array)
{
	t_node	*current;

	ft_printf("Stack %s (size: %d):\n", name, stack->size);
	current = stack->top;
	while (current)
	{
		ft_printf("  Node index: %d, Original value: %d, Address: %p\n",
				  current->value, sorted_array[current->value], (void *)current);
		current = current->next;
	}
	ft_printf("End of stack %s.\n", name);
}

void	print_stack_new(t_stack *stack, char *name)
{
	t_node	*current;

	ft_printf("Stack %s (size: %d):\n", name, stack->size);
	current = stack->top;
	while (current)
	{
		ft_printf("%d -> ", current->value);
		current = current->next;
	}
	ft_printf("NULL\n");
}