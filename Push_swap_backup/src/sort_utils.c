/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:18:47 by clu               #+#    #+#             */
/*   Updated: 2025/01/31 12:12:36 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Find the index of the smallest number in the stack
// Loop through the stack and find the smallest number
// Return the index of the smallest number
int	find_min_index(t_stack *stack)
{
	t_node	*current;
	int		index;
	int		min_index;
	int		min;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	min = current->value;
	min_index = 0;
	index = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_index = index;
		}
		current = current->next;
		index++;
	}
	return (min_index);
}

// Move the smallest number to the top of the stack
// If the index is less than half the size of the stack, rotate forward
// If the index is more than half the size of the stack, reverse rotate
void	move_min_to_top(t_stack *stack, int min_index)
{
	if (min_index == 0)
		return ;
	if (min_index <= stack->size / 2)
	{
		while (min_index-- > 0)
			ra(stack);
	}
	else
	{
		while (min_index++ < stack->size)
			rra(stack);
	}
}

// Find the index of the largest number in the stack
// Loop through the stack and find the largest number
// Return the index of the largest number
int	find_max_index(t_stack *stack)
{
	t_node	*current;
	int		max_value;
	int		max_index;
	int		index;

	if (!stack || !stack->top)
		return (-1);
	current = stack->top;
	max_value = current->value;
	max_index = 0;
	index = 0;
	while (current)
	{
		if (current->value > max_value)
		{
			max_value = current->value;
			max_index = index;
		}
		current = current->next;
		index++;
	}
	return (max_index);
}

// Move the largest number to the top of the stack
// If the index is less than half the size of the stack, rotate forward
// If the index is more than half the size of the stack, reverse rotate
void	move_max_to_top(t_stack *stack, int max_index)
{
	if (max_index == 0)
		return ;
	if (max_index <= stack->size / 2)
	{
		while (max_index-- > 0)
			ra(stack);
	}
	else
	{
		while (max_index++ < stack->size)
			rra(stack);
	}
}
