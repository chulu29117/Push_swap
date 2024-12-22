/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clu <clu@student.hive.fi>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:51:44 by clu               #+#    #+#             */
/*   Updated: 2024/12/22 21:37:06 by clu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <stdlib.h>
# include <limits.h>

typedef struct s_node{
	int				value;
	struct s_node	*next;
} t_node;

typedef struct s_stack{
	t_node	*top;
	t_node	*bottom;
	int		size;
} t_stack;

t_stack	*init_stack(void);
void	push(t_stack *stack, int value);
int		pop(t_stack *stack);
void	free_stack(t_stack *stack);
int		peek(t_stack *stack);

int		is_valid_input(const char *input);
int		duplicates(t_stack *stack, int value);
int		parse_input(t_stack *stack, int argc, char **argv);

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

void	print_stack(t_stack *stack, char *name);

#endif
