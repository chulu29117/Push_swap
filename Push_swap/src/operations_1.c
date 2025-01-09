/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:52:52 by clu               #+#    #+#             */
/*   Updated: 2025/01/08 17:33:24 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

///// Basic push and swap operations /////
// Swap first 2 elements at the top of stack_a
void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || stack_a->size < 2)
		return ;					// no need to swap if less than 2 elements
	first = stack_a->top;			// first node
	second = first->next;			// second node
	first->next = second->next;		// first node points to the node after second
	second->next = first;			// second node points to first node
	stack_a->top = second;			// update top to second node
	if (stack_a->size == 2)
		stack_a->bottom = first;	// update bottom if only 2 elements
	ft_printf("sa\n");
}

// Swap first 2 elements at the top of stack_b
void	sb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b || stack_b->size < 2)
		return ;
	first = stack_b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_b->top = second;
	if (stack_b->size == 2)
		stack_b->bottom = first;
	ft_printf("sb\n");
}

// Swap first 2 elements at the top for both stack_a&b
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->size >= 2) // Ensure valid stack_a
		sa(stack_a);
	if (stack_b && stack_b->size >= 2) // Ensure valid stack_b
		sb(stack_b);
	ft_printf("ss\n");
}

// Push stack_b top to stack_a top
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	int	*value;

	if (!stack_a || !stack_b || stack_b->size == 0) // NULL check
		return ;
	value = pop(stack_b);	// Remove top stack_b
	if (!value)
		return ;
	if (!stack_a->top)
	{
		free(value);
		return ;
	}
	push(stack_a, *value);	// Push the value to stack_a
	free(value);
	ft_printf("pa\n");
}

// Push stack_a top to stack_b top
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	int	*value;

	if (!stack_a || !stack_b || stack_a->size == 0) // NULL check
		return ;
	value = pop(stack_a);
	if (!value)
		return ;
	if (!stack_b)
	{
		free(value);
		return ;
	}
	push(stack_b, *value);
	free(value);
	ft_printf("pb\n");
}
