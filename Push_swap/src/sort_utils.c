/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:18:47 by clu               #+#    #+#             */
/*   Updated: 2025/01/14 12:36:36 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_stack *stack_a)
{
	t_node	*current;
	int		index;
	int		min_index;
	int		min;

	if (!stack_a || !stack_a->top)
		return (-1);
	current = stack_a->top;
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

void	move_min_to_top(t_stack *stack_a, int min_index)
{
	if (min_index == 0)
		return ;
	if (min_index <= stack_a->size / 2)
	{
		while (min_index-- > 0)
			ra(stack_a);
	}
	else
	{
		min_index = stack_a->size - min_index;
		while (min_index-- > 0)
			rra(stack_a);
	}
}

int	get_max_bits(t_stack *stack)
{
	t_node	*current;
	int		max_value;
	int		max_bits;

	if (!stack || !stack->top)
		return (0);
	current = stack->top;
	max_value = current->value;
	while (current)
	{
		if (current->value > max_value)
			max_value = current->value;
		current = current->next;
	}
	max_bits = 0;
	while ((max_value >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
