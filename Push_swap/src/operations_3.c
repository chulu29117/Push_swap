/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:53:07 by clu               #+#    #+#             */
/*   Updated: 2024/12/21 15:31:36 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///// Reverse rotation operations /////
// Shift down all elements of stack_a by 1
void	rra(t_stack *stack_a)
{
	t_node	*current;
	t_node	*old_bottom;

	if (stack_a->size < 2)
		return ;
	current = stack_a->top;
	while (current->next != stack_a->bottom)
		current = current->next;			// reverse to the second last node
	old_bottom = stack_a->bottom;			// save the bottom
	current->next = NULL;					// detach the bottom node
	old_bottom->next = stack_a->top;		// link the old_bottom to the top
	stack_a->top = old_bottom;				// update top pointer
	stack_a->bottom = current;				// update bottom pointer
}

// Shift down all elements of stack_b by 1
void	rrb(t_stack *stack_b)
{
	rrb(stack_b);
}

// Run rra and rrb at the same time
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	ra(stack_b);
}
