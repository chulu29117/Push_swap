/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:53:11 by clu               #+#    #+#             */
/*   Updated: 2025/01/08 16:44:47 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///// Rotation operators /////
// Shift up all elements of stack_a by 1
void	ra(t_stack *stack_a)
{
	t_node	*old_top;

	if (!stack_a || stack_a->size < 2)
		return ;
	old_top = stack_a->top;			// Save the top
	stack_a->top = old_top->next;	// Move next node to top
	stack_a->bottom = old_top;		// Link the old_top to the bottom
	old_top->next = NULL;			// Mark the new bottom as tht end
	ft_printf("ra\n");
}

// Shift up all elements of stack_b by 1
void	rb(t_stack *stack_b)
{
	t_node	*old_top;

	if (!stack_b || stack_b->size < 2)
		return ;
	old_top = stack_b->top;
	stack_b->top = old_top->next;
	stack_b->bottom->next = old_top;
	stack_b->bottom = old_top;
	old_top->next = NULL;
	ft_printf("rb\n");
}

// Do ra and rb at the same time
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->size >= 2)
		ra(stack_a);
	if (stack_b && stack_b->size >= 2)
		rb(stack_b);
	ft_printf("rr\n");
}
