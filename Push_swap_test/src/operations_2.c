/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:53:11 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 10:49:58 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///// Rotation operators /////
// Shift up all elements of stack_a by 1
void	ra(t_stack *stack_a)
{
	t_node	*temp;

	if (!stack_a || stack_a->size < 2)
		return ;
	temp = stack_a->top;			// Save the top
	stack_a->top = stack_a->top->next;	// Move next node to top
	temp->next = NULL;			// Mark the new bottom as tht end
	stack_a->bottom->next = temp;
	stack_a->bottom = temp;
	// ft_printf("ra: rotated node with value: %d\n", temp->value);
	ft_printf("ra\n");
}

// Shift up all elements of stack_b by 1
void	rb(t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_b || stack_b->size < 2)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->bottom = temp;
	temp->next = NULL;
	stack_b->bottom->next = temp;
	stack_b->bottom = temp;
	// ft_printf("rb: rotated node with value: %d\n", temp->value);
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
