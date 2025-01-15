/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 20:19:29 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 17:41:56 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

// Check if the input is a valid int
int	is_valid_input(const char *arg)
{
	int		i;
	long	value;

	if (!arg || *arg == '\0')
		return (0);
	i = 0;
	if (arg[i] == '+' || arg[i] == '-')
	{
		i++;
		if (arg[i] == '\0')
			return (0);
	}
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	value = ft_atol(arg);
	if (value < INT_MIN || value > INT_MAX)
		return (0);
	return (1);
}

int	duplicates(t_stack *stack, int value)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	is_empty_string(const char *str)
{
	int	i;

	if (!str || *str == '\0')
		return (1);
	i = 0;
	while (str[i])
	{
		if (!(str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
			return (0);
		i++;
	}
	return (1);
}
