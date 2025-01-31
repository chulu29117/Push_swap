/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:33:04 by clu               #+#    #+#             */
/*   Updated: 2025/01/31 10:33:22 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_split(t_stack *stack, char **split)
{
	int		i;
	int		value;

	i = 0;
	while (split[i])
	{
		if (!is_valid_input(split[i]) || duplicates(stack, ft_atoi(split[i])))
		{
			ft_free_split(split);
			return (0);
		}
		value = ft_atoi(split[i]);
		if (!push(stack, value))
		{
			ft_free_split(split);
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
		return (0);
	split = ft_split(arg, ' ');
	if (!split || !*split)
	{
		ft_free_split(split);
		return (0);
	}
	return (process_split(stack, split));
}

static int	process_arg(t_stack *stack, char *arg)
{
	int		value;

	if (!is_valid_input(arg) || duplicates(stack, ft_atoi(arg)))
		return (0);
	value = ft_atoi(arg);
	if (!push(stack, value))
		return (0);
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
