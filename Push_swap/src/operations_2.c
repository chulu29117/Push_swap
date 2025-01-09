/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:53:11 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 12:49:21 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack_a)
{
	t_node	*temp;

	if (!stack_a || stack_a->size < 2)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	temp->next = NULL;
	stack_a->bottom->next = temp;
	stack_a->bottom = temp;
	ft_printf("ra\n");
}

void	rb(t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_b || stack_b->size < 2)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	stack_b->bottom = temp;
	temp->next = NULL;
	stack_b->bottom->next = temp;
	stack_b->bottom = temp;
	ft_printf("rb\n");
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->size >= 2)
		ra(stack_a);
	if (stack_b && stack_b->size >= 2)
		rb(stack_b);
	ft_printf("rr\n");
}
