/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:26:14 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 23:32:16 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Sort 2 elements
void	sort_two(t_stack *stack_a)
{
	if (stack_a->top == NULL)
		return ;
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a);	// swap top 2 elements
}

// Sort 3 elements
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
		sa(stack_a);	// Case 1: 2 1 3
	else if (first > second && second < third && first > third)
		ra(stack_a);	// Case 2: 3 1 2
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);	// Case 3: 1 3 2
	}
	else if (first > second && second > third)
	{
		sa(stack_a);
		rra(stack_a);	// Case 4: 3 2 1
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);	// Case 5: 2 3 1
}

// Find the min index and push to stack_b
int	find_min_index(t_stack *stack_a)
{
	t_node	*current;
	int		index;
	int		min_index;
	int		min;

	if (stack_a->top == NULL)
		return (-1);
	current = stack_a->top;		// points to the top of stack
	min = current->value;		// stores the first value as the smallest candidate
	min_index = 0;
	index = 0;					// current position
	while (current)				// loop through until current becomes NULL
	{
		if (current->value < min)	// compare current value with min
		{
			min = current->value;	// undate min to current value
			min_index = index;		// update min_index to current index
		}
		current = current->next;	// go to the next node
		index++;
	}
	return (min_index);
}

// Sort 4&5 elements
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
			if (min_index <= stack_a->size / 2)	// if index is before mid point
				ra(stack_a);					// rotate up
			else
				rra(stack_a);					// rotate down

		}
		if (stack_a->size > 0 && stack_a->top != NULL)
			pb(stack_a, stack_b);
		else
			return ;
	}
	sort_three(stack_a);	// sort the remaining 3 elements
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
