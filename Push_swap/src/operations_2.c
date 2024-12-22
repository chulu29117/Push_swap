/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:53:11 by clu               #+#    #+#             */
/*   Updated: 2024/12/21 15:31:34 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///// Rotation operators /////
// Shift up all elements of stack_a by 1
void	ra(t_stack *stack_a)
{
	t_node	*old_top;

	if (stack_a->size < 2)
		return ;
	old_top = stack_a->top;				// Save the top
	stack_a->top = old_top->next;		// Move next node to top
	stack_a->bottom->next = old_top;	// Link the old_top to the bottom
	old_top->next = NULL;				// Mark the new bottom as tht end
}

// Shift up all elements of stack_b by 1
void	rb(t_stack *stack_b)
{
	ra(stack_b);
}

// Do ra and rb at the same time
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	ra(stack_b);
}
