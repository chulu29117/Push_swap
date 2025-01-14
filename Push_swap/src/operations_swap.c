/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:52:52 by clu               #+#    #+#             */
/*   Updated: 2025/01/14 13:25:44 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sa(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	swap_stack(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	if (!stack_b || stack_b->size < 2)
		return ;
	swap_stack(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->size >= 2)
		swap_stack(stack_a);
	if (stack_b && stack_b->size >= 2)
		swap_stack(stack_b);
	ft_printf("ss\n");
}
