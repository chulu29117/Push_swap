/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:53:11 by clu               #+#    #+#             */
/*   Updated: 2025/01/31 16:04:54 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate the stack by moving the top element to the bottom
static void	rotate(t_stack *stack)
{
	t_node	*temp;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->top;
	stack->top = stack->top->next;
	temp->next = NULL;
	stack->bottom->next = temp;
	stack->bottom = temp;
}

// Rotate the first element of stack A to the bottom
void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

// Rotate the first element of stack B to the bottom
void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

// Rotate the first element of both stacks
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
