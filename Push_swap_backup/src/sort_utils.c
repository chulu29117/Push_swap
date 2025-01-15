/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:18:47 by clu               #+#    #+#             */
/*   Updated: 2025/01/15 11:41:19 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
