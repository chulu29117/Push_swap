/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:53:11 by clu               #+#    #+#             */
/*   Updated: 2025/01/14 13:25:41 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ra(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	if (!stack_b || stack_b->size < 2)
		return ;
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->size >= 2)
		rotate(stack_a);
	if (stack_b && stack_b->size >= 2)
		rotate(stack_b);
	ft_printf("rr\n");
}
