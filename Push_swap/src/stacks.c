/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:32:54 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 23:27:34 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*pop(t_stack *stack)
{
	t_node	*temp;
	int		*value;

	if (!stack || !stack->top)
		return (NULL);
	temp = stack->top;
	value = malloc(sizeof(int));
	if (!value)
		return (free(temp), NULL);
	*value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value);
}

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
