/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:26:14 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 23:32:06 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack *stack_a)
{
	if (stack_a == NULL)
		return ;
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a);
}

void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	if (stack_a == NULL)
		return ;
	first = stack_a->top->value;
	second = stack_a->top->next->value;
	third = stack_a->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

int	find_min_index(t_stack *stack_a)
{
	t_node	*current;
	int		index;
	int		min_index;
	int		min;

	if (stack_a->top == NULL)
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

void	sort_four_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;

	if (stack_a == NULL || stack_b == NULL || stack_a->size < 4)
		return ;
	while (stack_a->size > 3)
	{
		min_index = find_min_index(stack_a);
		if (min_index == -1)
			return ;
		while ((min_index = find_min_index(stack_a)) > 0)
		{
			if (min_index <= stack_a->size / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		if (stack_a->size > 0 && stack_a->top != NULL)
			pb(stack_a, stack_b);
		else
			return ;
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
