/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:33:04 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 23:28:00 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_split(t_stack *stack, char **split)
{
	int		i;
	int		value;
	t_node	*new_node;

	i = 0;
	while (split[i])
	{
		if (!is_valid_input(split[i]) || duplicates(stack, ft_atoi(split[i])))
			return (ft_free_split(split), ft_putstr_fd("Error\n", 2), 0);
		value = ft_atoi(split[i]);
		new_node = malloc(sizeof(t_node));
		if (!new_node)
			return (ft_free_split(split), free_stack(&stack), 0);
		free(new_node);
		if (!push(stack, value))
		{
			ft_putstr_fd("Error\n", 2);
			ft_free_split(split);
			free_stack(&stack);
			return (0);
		}
		i++;
	}
	ft_free_split(split);
	return (1);
}

int	process_split_input(t_stack *stack, char *arg)
{
	char	**split;

	if (is_empty_string(arg))
		return (ft_putstr_fd("Error\n", 2), 0);
	split = ft_split(arg, ' ');
	if (!split || !*split)
	{
		ft_free_split(split);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!process_split(stack, split))
		return (0);
	return (1);
}

static int	process_arg(t_stack *stack, char *arg)
{
	int		value;
	t_node	*new_node;

	if (!is_valid_input(arg) || duplicates(stack, ft_atoi(arg)))
		return (ft_putstr_fd("Error\n", 2), 0);
	value = ft_atoi(arg);
	new_node = malloc(sizeof(t_node));
	if (!new_node)
	{
		free_stack(&stack);
		exit(1);
	}
	free(new_node);
	if (!push(stack, value))
		handle_error(stack, NULL, NULL, NULL);
	return (1);
}

int	parse_input(t_stack *stack, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchr(argv[i], ' '))
		{
			if (!process_split_input(stack, argv[i]))
				return (0);
		}
		else
		{
			if (!process_arg(stack, argv[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
