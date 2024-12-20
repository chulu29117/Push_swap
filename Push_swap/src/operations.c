/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:32:54 by clu               #+#    #+#             */
/*   Updated: 2024/12/20 23:10:27 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

// Initialize empty stack
t_stack	*init_stack(void)
{
	t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
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
	
	new_node= (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;	// sets the value field of the new_node to the given value
	new_node->next = stack->top;	// point new_node to the top node
	stack->top = new_node;		// update top pointer to the new_node
	// if stack empty, set bottom to new node
	if (stack->size == 0)
		stack->bottom = new_node;
	stack->size++;
}

// Pop a value from the stack
int	pop(t_stack *stack)
{
	t_node 	*temp;
	int		value;
	
	if (stack->size == 0)
		return (-1);	// empty stack
	temp = stack->top;
	value = temp->value;
	stack->top = stack->top->next;
	
}