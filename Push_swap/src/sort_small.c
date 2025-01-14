/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:26:14 by clu               #+#    #+#             */
/*   Updated: 2025/01/14 16:17:05 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to sort a stack with two elements
static void	sort_two(t_stack *stack)
{
	if (!stack)
		return ;
	if (stack->top->value > stack->top->next->value)
		sa(stack);
}

// Function to sort a stack with three elements
static void	sort_three(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack)
		return ;
	first = stack->top->value;
	second = stack->top->next->value;
	third = stack->top->next->next->value;
	if (first > second && second < third && first < third)
		sa(stack);
	else if (first > second && second < third && first > third)
		ra(stack);
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first > second && second > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
}

// Function to sort a stack with four or five elements
static void	sort_four_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min_index;

	if (!stack_a || !stack_b || stack_a->size < 4)
		return ;
	while (stack_a->size > 3)
	{
		min_index = find_min_index(stack_a);
		if (min_index == -1)
			return ;
		move_min_to_top(stack_a, min_index);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}

// Choosing which small sort to use
void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = stack_a->size;
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_four_five(stack_a, stack_b);
}
