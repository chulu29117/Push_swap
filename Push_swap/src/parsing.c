/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:33:04 by clu               #+#    #+#             */
/*   Updated: 2025/01/08 19:13:12 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Process split input
static int	process_split(t_stack *stack, char **split)
{
	int		i;
	int		value;
	t_node *new_node;

	i = 0;
	while (split[i])
	{
		if (!is_valid_input(split[i]) || duplicates(stack, ft_atoi(split[i])))	// validate input and check for duplicates
			return(ft_free_split(split), free_stack(&stack), 0);
		value = ft_atoi(split[i]);
		new_node = malloc(sizeof(t_node));
		if (!new_node) 			// Check memory allocation
			return(ft_free_split(split), free_stack(&stack), 0);
		free(new_node); 		// Temporary allocation check
		if (!push(stack, value))
    		return(ft_free_split(split), free_stack(&stack), 0);
		i++;
	}
	ft_free_split(split); // Free split after processing
	return (1);
}

// Process single arg
static int	process_arg(t_stack *stack, char *arg)
{
	int	value;
	t_node *new_node;

	// validate single argc
	if (!is_valid_input(arg) || duplicates(stack, ft_atoi(arg)))
		return (0);
	value = ft_atoi(arg);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free_stack(&stack);
		exit(1);
	}
	free(new_node);
	if (!push(stack, value))	 // Push value safely
    	handle_error(stack, NULL, NULL, NULL);	// No unlinked node to free here
	return (1);
}

// Process input with split arguments
static int	process_split_input(t_stack *stack, char *arg)
{
	char	**split;

	split = ft_split(arg, ' ');
	if (!split) // Allocation failure
		return (0);
	if (!split[0]) // Empty split
	{
		ft_free_split(split);
		return (0);
	}
	if (!process_split(stack, split)) 	// Process split input
		return (0); 					// No need for double free, already freed inside
	return (1);
}

// Parse user input argv
int	parse_input(t_stack *stack, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' ')) // Split input
		{
			if (!process_split_input(stack, argv[i]))
				return (free_stack(&stack), 0);
		}
		else // Single input
		{
			if (!process_arg(stack, argv[i]))
				return (free_stack(&stack), 0);
		}
		i++;
	}
	return (1);
}

