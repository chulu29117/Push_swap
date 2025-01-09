/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:32:54 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 11:30:13 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// Initialize empty stack
t_stack	*init_stack(void)
{
	t_stack *stack;
	
	stack = ft_calloc(1, sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

// Add a value to the stack
int	push(t_stack *stack, int value)
{
	t_node *new_node;
	t_node *current;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (0);
	new_node->value = value;
	new_node->next = NULL;

	if (stack->size == 0) // If the stack is empty
	{
		stack->top = new_node;
		stack->bottom = new_node;
	}
	else // Add to the bottom
	{
		current = stack->bottom;
		current->next = new_node; // Link the new node to the bottom
		stack->bottom = new_node; // Update the bottom pointer
	}
	stack->size++;
	// ft_printf("Allocated node with value: %d at address: %p\n", value, (void *)new_node);
	// ft_printf("Pushed node with value: %d\n", new_node->value);
	// if (new_node->next)
		// ft_printf("Node %d points to node %d\n", new_node->value, new_node->next->value);
	// else
		// ft_printf("Node %d points to NULL\n", new_node->value);
	return (1);
}

// Pop a value from the stack
int	*pop(t_stack *stack)
{
	t_node 	*temp;	// temp pointer for the top node
	int		*value;	// value to store the value of the top node

	if (!stack || !stack->top)	// NULL or empty check
		return (NULL);			// Return error code for invalid pop
	temp = stack->top;			// save current top node in temp
	value = malloc(sizeof(int));
	if (!value)
		return (free (temp), NULL);
	*value = temp->value;		// store value of top node in value
	stack->top = temp->next;	// top to the next node
	free(temp);
	stack->size--;
	return (value);
}

void	free_stack(t_stack **stack)
{
	t_node	*temp;

	if (!stack) 	// NULL check
		return ;
	while ((*stack)->top) 	// Free all nodes safely
	{
		temp = (*stack)->top;
		(*stack)->top = (*stack)->top->next;
		// ft_printf("Freeing node with value: %d at address: %p\n", temp->value, (void *)temp);
		free(temp);
	}
	free(*stack); 			// Free stack structure
	*stack = NULL;
}
