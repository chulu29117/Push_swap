/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:32:54 by clu               #+#    #+#             */
/*   Updated: 2025/02/03 15:51:04 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Initialize a new stack
t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

// Push a new value to the stack
// Create a new node and assign the value
// If the stack is empty, assign the new node to top and bottom
// If the stack is not empty, assign the new node to the bottom
// Increase the size of the stack
int	push(t_stack *stack, int value)
{
	t_node	*new_node;
	t_node	*current;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = NULL;
	if (stack->size == 0)
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else
	{
		current = stack->bottom;
		current->next = new_node;
		stack->bottom = new_node;
	}
	stack->size++;
	return (1);
}

// Free the stack and all nodes
// Loop through the stack and free each node
// Free the stack
void	free_stack(t_stack **stack)
{
	t_node	*temp;

	if (!stack || !*stack)
		return ;
	while ((*stack)->top)
	{
		temp = (*stack)->top;
		(*stack)->top = (*stack)->top->next;
		free(temp);
	}
	free(*stack);
	*stack = NULL;
}
