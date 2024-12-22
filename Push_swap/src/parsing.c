/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:33:04 by clu               #+#    #+#             */
/*   Updated: 2024/12/22 21:39:34 by clu              ###   ########.fr       */
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

// Process split input
static int	process_split(t_stack *stack, char **split)
{
	int	i;
	int	value;

	i = 0;
	while (split[i])
	{
		// validate input and check for duplicates
		if(!is_valid_input(split[i]) || duplicates(stack, ft_atoi(split[i])))
		{
			ft_free_split(split);
			free_stack(stack);
			return (0);
		}
		value = ft_atoi(split[i]);
		push(stack, value);
		i++;
	}
	ft_free_split(split);
	return (1);
}

// Process single arg
static int	process_arg(t_stack *stack, char *arg)
{
	int	value;

	// validate single argc
	if(!is_valid_input(arg) || duplicates(stack, ft_atoi(arg)))
	{
		free_stack(stack);
		return (0);
	}
	value = ft_atoi(arg);
	push(stack, value);
	return (1);
}

// Parse user input argv
int	parse_input(t_stack *stack, int argc, char **argv)
{
	int		i;
	char	**split;
	
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			split = ft_split(argv[i], ' ');
			if (!split)
				return (0);
			if(!process_split(stack, split))		// process split input
				return (0);
		}
		else
		{
			if(!process_arg(stack, argv[i]))		// check arg
				return (0);
		}
		i++;
	}
	return (1);
}

