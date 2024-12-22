/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:49:24 by clu               #+#    #+#             */
/*   Updated: 2024/12/22 21:41:26 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void	print_stack(t_stack *stack, char *name)
{
	t_node	*current;

	ft_printf("Stack %s (size: %d):\n", name, stack->size);
	current = stack->top;
	while (current)
	{
		ft_printf("%d\n", current->value);
		current = current->next;
	}
}
