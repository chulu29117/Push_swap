/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:52:52 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 15:07:50 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	if (!stack_a || stack_a->size < 2)
		return ;
	first = stack_a->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_a->top = second;
	if (stack_a->size == 2)
		stack_a->bottom = first;
	ft_printf("sa\n");
}

void	sb(t_stack *stack_b)
{
	t_node	*first;
	t_node	*second;

	if (!stack_b || stack_b->size < 2)
		return ;
	first = stack_b->top;
	second = first->next;
	first->next = second->next;
	second->next = first;
	stack_b->top = second;
	if (stack_b->size == 2)
		stack_b->bottom = first;
	ft_printf("sb\n");
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_a->size >= 2)
		sa(stack_a);
	if (stack_b && stack_b->size >= 2)
		sb(stack_b);
	ft_printf("ss\n");
}

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
