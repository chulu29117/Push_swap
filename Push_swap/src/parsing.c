/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:33:04 by clu               #+#    #+#             */
/*   Updated: 2025/01/07 21:11:09 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		return (0);
	value = ft_atoi(arg);
	push(stack, value);
	return (1);
}

// Process input
static int	process_split_input(t_stack *stack, char *arg)
{
	char	**split;
	
	split = ft_split(arg, ' ');
	if (!split) // Check for allocation failure
		return (0);
	if (!split[0]) // Check for empty split
	{
		ft_free_split(split);
		return (0);
	}
	if (!process_split(stack, split)) // Process split input
		return (0);
	return (1);
}

// Parse user input argv
int	parse_input(t_stack *stack, int argc, char **argv)
{
	int		i;
	
	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (!process_split_input(stack, argv[i]))
			{
				free_stack(stack);
				return (0);
			}
		}
		else
		{
			if(!process_arg(stack, argv[i]))	// check arg
			{
				free_stack(stack);
				return (0);
			}
		}
		i++;
	}
	return (1);
}
