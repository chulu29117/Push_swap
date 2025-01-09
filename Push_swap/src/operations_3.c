/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:53:07 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 13:13:48 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack_a)
{
	t_node	*current;
	t_node	*old_bottom;

	if (!stack_a || stack_a->size < 2 || !stack_a->bottom)
		return ;
	current = stack_a->top;
	while (current->next != stack_a->bottom)
		current = current->next;
	old_bottom = stack_a->bottom;
	current->next = NULL;
	old_bottom->next = stack_a->top;
	stack_a->top = old_bottom;
	stack_a->bottom = current;
	ft_printf("rra\n");
}

void	rrb(t_stack *stack_b)
{
	t_node	*current;
	t_node	*old_bottom;

	if (!stack_b || stack_b->size < 2)
		return ;
	current = stack_b->top;
	while (current->next != stack_b->bottom)
		current = current->next;
	old_bottom = stack_b->bottom;
	current->next = NULL;
	old_bottom->next = stack_b->top;
	stack_b->top = old_bottom;
	stack_b->bottom = current;
	ft_printf("rrb\n");
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->size >= 2)
		rra(stack_a);
	if (stack_b && stack_b->size >= 2)
		rrb(stack_b);
	ft_printf("rrr\n");
}
