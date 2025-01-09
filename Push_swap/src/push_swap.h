/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:51:44 by clu               #+#    #+#             */
/*   Updated: 2025/01/09 15:06:48 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

// Stack manipulation
t_stack	*init_stack(void);
int		push(t_stack *stack, int value);
int		*pop(t_stack *stack);
void	free_stack(t_stack **stack);
int		peek(t_stack *stack);

// Parsing input arguments
int		is_valid_input(const char *input);
int		duplicates(t_stack *stack, int value);
int		parse_input(t_stack *stack, int argc, char **argv);

// Operations
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);

// Sorting small 
void	sort_two(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
int		find_min_index(t_stack *stack_a);
void	sort_four_five(t_stack *stack_a, t_stack *stack_b);

// Sorting large
int		*copy_stack_to_array(t_stack *stack, int size);
void	sort_array(int	*array, int size);
void	norm_indices(t_stack *stack_a, int *array, int size);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

// Errors
void	handle_error(t_stack *stack_a, t_stack *stack_b,
			int *array, t_node *temp_node);

// Debug
// void	print_stack(t_stack *stack, char *name, int *sorted_array);
// void	print_stack_new(t_stack *stack, char *name);

#endif
