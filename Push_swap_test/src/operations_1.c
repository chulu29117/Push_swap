/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:52:52 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 10:50:09 by clu              ###   ########.fr       */
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
	t_node	*temp;

	if (!stack_b || !stack_b->top) // Check if stack_b is empty
		return ; 
	temp = stack_b->top;          // Save the top node of stack_b
	stack_b->top = stack_b->top->next; // Move stack_b's top pointer to the next node
	if (!stack_b->top)
		stack_b->bottom = NULL;   // If stack_b is now empty, update bottom pointer
	temp->next = stack_a->top;    // Point the node to stack_a's current top
	stack_a->top = temp;          // Update stack_a's top pointer to the moved node
	if (stack_a->size == 0)
		stack_a->bottom = temp;   // If stack_a was empty, update its bottom pointer
	stack_b->size--;              // Decrease size of stack_b
	stack_a->size++;              // Increase size of stack_a
	// ft_printf("pa: moved node with value: %d\n", temp->value);
	ft_printf("pa\n");            // Print operation
}


// Push stack_a top to stack_b top
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_a || !stack_a->top)
		return ;
	temp = stack_a->top; 			// Save top node from stack_a
	stack_a->top = stack_a->top->next; 	// Move stack_a top pointer
	if (!stack_a->top)
		stack_a->bottom = NULL; 	// Update bottom if stack_a is empty
	temp->next = stack_b->top; 		// Point temp to stack_b's current top
	stack_b->top = temp; 			// Make temp the new top of stack_b
	if (stack_b->size == 0)
		stack_b->bottom = temp;		// Update bottom if stack_b was empty
	stack_a->size--;
	stack_b->size++;
	// ft_printf("pb: moved node with value: %d\n", temp->value);
	ft_printf("pb\n");
}
