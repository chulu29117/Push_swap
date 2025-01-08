/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:19:29 by clu               #+#    #+#             */
/*   Updated: 2025/01/07 20:19:58 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

// Check if the input is a valid int
int	is_valid_input(const char *input)
{
	int			i;
	long long	value;

	if (!input || *input == '\0')	// Empty or NULL string
		return (0);
	i = 0;
	if (input[i] == '+' || input[i] == '-')
	{
		i++;
		if (input[i] == '\0')		// Reject '+' or '-' alone
			return (0);
	}
	while (input[i])
	{
		if(!ft_isdigit(input[i]))	// Validate digits
			return (0);
		i++;
	}
	value = ft_atoll(input);
	if (value < INT_MIN || value > INT_MAX)
		return (0);
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
			return (1);
		current = current->next;
	}
	return (0);
}
