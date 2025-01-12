/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 13:48:41 by clu               #+#    #+#             */
/*   Updated: 2025/01/10 13:30:23 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Free memory and exit with error
void	print_error(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(&stack_a);
	free_stack(&stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
