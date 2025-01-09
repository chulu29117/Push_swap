/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:19:29 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 12:08:27 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

// Check if the input is a valid int
int	is_valid_input(const char *arg)
{
	int		i;
	long	value;

	if (!arg || *arg == '\0')	// Empty or NULL string
		return (0);
	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
	{
		i++;
		if (arg[i] == '\0')		// Reject '+' or '-' alone
			return (0);
	}
	while (arg[i])
	{
		if(!ft_isdigit(arg[i]))	// Validate digits
			return (0);
		i++;
	}
	value = ft_atol(arg);
	if (value < INT_MIN || value > INT_MAX)
	{
		ft_printf("Error: Invalid INT\n");
		exit(EXIT_FAILURE);
	}
	return (1);
}

// Check for duplicate values
int	duplicates(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)	// duplicates found
		{
			ft_printf("Error: Duplicates\n");
			exit(EXIT_FAILURE);
		}
		current = current->next;
	}
	return (0);
}
