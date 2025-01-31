/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:53:07 by clu               #+#    #+#             */
/*   Updated: 2025/01/31 11:58:10 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Reverse rotate the stack by moving the bottom element to the top
static void	reverse_rotate(t_stack *stack)
{
	t_node	*current;
	t_node	*old_bottom;

	current = stack->top;
	while (current->next != stack->bottom)
		current = current->next;
	old_bottom = stack->bottom;
	current->next = NULL;
	old_bottom->next = stack->top;
	stack->top = old_bottom;
	stack->bottom = current;
}

// Reverse rotate the bottom element of stack A
void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

// Reverse rotate the bottom element of stack B
void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

// Reverse rotate the bottom element of both stacks
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
