/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:32:54 by clu               #+#    #+#             */
/*   Updated: 2025/01/07 20:47:42 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// Initialize empty stack
t_stack	*init_stack(void)
{
	t_stack *stack;
	
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->bottom = NULL;
	stack->size = 0;
	return (stack);
}

// Add a value to the stack
void	push(t_stack *stack, int value)
{
	// add new_node with given value to the top
	t_node *new_node;
	
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return ;
	new_node->value = value;		// sets the value field of the new_node to the given value
	new_node->next = stack->top;	// point new_node to the top node
	stack->top = new_node;			// update top pointer to the new_node
	if (stack->size == 0)
		stack->bottom = new_node;	// if stack empty, set bottom to new node
	stack->size++;
}

// Pop a value from the stack
int	pop(t_stack *stack)
{
	// temp pointer for the top node
	t_node 	*temp;
	int		value;	// value to store the value of the top node

	if (!stack || !stack->top)	// NULL or empty check
		return (-1);			// Return error code for invalid pop
	temp = stack->top;			// save current top node in temp
	value = temp->value;		// store value of top node in value
	stack->top = temp->next;	// top to the next node
	free(temp);
	stack->size--;
	return (value);
}

void	free_stack(t_stack *stack)
{
	t_node	*temp;

	if (!stack) // NULL check
		return ;
	while (stack->top) // Free all nodes safely
	{
		temp = stack->top;
		stack->top = stack->top->next;
		free(temp);
	}
	free(stack); // Free stack structure
}


int	peek(t_stack *stack)
{
	if (stack->size == 0)
		return (-1);
	return (stack->top->value);
}
