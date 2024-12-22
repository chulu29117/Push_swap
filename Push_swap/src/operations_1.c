/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:52:52 by clu               #+#    #+#             */
/*   Updated: 2024/12/21 15:31:32 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///// Basic push and swap operations /////
// Swap first 2 elements at the top of stack_a
void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (stack_a->size < 2)
		return ;				// no need to swap if less than 2 elements
	first = stack_a->top;		// first node
	second = first->next;		// second node
	first->next = second->next;	// first node points to the node after second
	second->next = first;		// second node points to first node
	stack_a->top = second;		// update top to second node
	if (stack_a->size == 2)
		stack_a->bottom = first;	// update bottom if only 2 elements
}

// Swap first 2 elements at the top of stack_b
void	sb(t_stack *stack_b)
{
	sa(stack_b);
}

// Swap first 2 elements at the top for both stack_a&b
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sa(stack_b);
}

// Push stack_b top to stack_a top
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (stack_b->size == 0)	// if stack_b is empty
		return ;
	value = pop(stack_b);	// Remove top stack_b
	push(stack_a, value);	// Push the value to stack_a
}

// Push stack_a top to stack_b top
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	value;

	if (stack_a->size == 0)
		return ;
	value = pop(stack_a);
	push(stack_b, value);
}
