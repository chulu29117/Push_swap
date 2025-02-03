/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:52:52 by clu               #+#    #+#             */
/*   Updated: 2025/01/31 16:05:44 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first two elements of the stack
void	swap_stack(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	first = stack->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack->top = second;
	if (stack->size == 2)
		stack->bottom = first;
}

// Swap the first two elements of stack A
void	sa(t_stack *stack_a)
{
	swap_stack(stack_a);
	ft_printf("sa\n");
}

// Swap the first two elements of stack B
void	sb(t_stack *stack_b)
{
	swap_stack(stack_b);
	ft_printf("sb\n");
}

// Swap the first two elements of both stacks
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	ft_printf("ss\n");
}
