/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:24:40 by clu               #+#    #+#             */
/*   Updated: 2025/01/31 16:04:14 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap the first two elements of stack A
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_b || !stack_b->top)
		return ;
	temp = stack_b->top;
	stack_b->top = stack_b->top->next;
	if (!stack_b->top)
		stack_b->bottom = NULL;
	temp->next = stack_a->top;
	stack_a->top = temp;
	if (stack_a->size == 0)
		stack_a->bottom = temp;
	stack_b->size--;
	stack_a->size++;
	ft_printf("pa\n");
}

// Swap the first two elements of stack B
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_a || !stack_a->top)
		return ;
	temp = stack_a->top;
	stack_a->top = stack_a->top->next;
	if (!stack_a->top)
		stack_a->bottom = NULL;
	temp->next = stack_b->top;
	stack_b->top = temp;
	if (stack_b->size == 0)
		stack_b->bottom = temp;
	stack_a->size--;
	stack_b->size++;
	ft_printf("pb\n");
}
