/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpinto-l <mpinto-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/10 10:17:42 by mpinto-l          #+#    #+#             */
/*   Updated: 2026/07/10 10:17:44 by mpinto-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

# define FALSE 0
# define TRUE 1

// structs

typedef struct s_bench
{
	int			enabled;
	int			complexity;
	double		disorder;
	char		*strategy;

}	t_bench;

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;

}	t_node;

typedef struct s_chunk
{
	int	count;
	int	base;
	int	rest;
	int	start;
	int	size;

}	t_chunk;

typedef struct s_operations
{
	int		sa;
	int		sb;
	int		ss;
	int		pa;
	int		pb;
	int		ra;
	int		rb;
	int		rr;
	int		rra;
	int		rrb;
	int		rrr;
	int		total;

}	t_operations;

// algorithms/simple.c
int				stack_min(t_node *stack);
void			sort_three(t_node **stack);
void			small_sort(t_node **stack_a, t_node **stack_b);
size_t			bubble_sorting(t_node **stack);

// algorithms/medium.c
void			init_chunks(t_chunk *chunk, int stack_size);
void			push_chunk(t_node **stack_a, t_node **stack_b, t_chunk *chunck);
int				chunk_sorting(t_node **stack_a, t_node **stack_b);

// algorithms/complex.c
void			get_to_index(t_node **stack, int index);
int				find_pivot(t_node *stack, int size);
int				partition(t_node **stack_a, t_node **stack_b, int size);
void			quick_sort(t_node **stack_a, t_node **stack_b, int size);

// benchmark/bench.c
void			print_bench(void);

// benchmark/disorder.c
double			disorder_metric(t_node *stack);

// benchmark/operations.c
void			print_op(char *name);

// operators/
void			sa(t_node **stack);
void			sb(t_node **stack);
void			ss(t_node **stack_a, t_node **stack_b);
void			pa(t_node **stack_a, t_node **stack_b);
void			pb(t_node **stack_b, t_node **stack_a);
void			ra(t_node **stack_a);
void			rb(t_node **stack_b);
void			rr(t_node **stack_a, t_node **stack_b);
void			rra(t_node **stack_a);
void			rrb(t_node **stack_b);
void			rrr(t_node **stack_a, t_node **stack_b);

// parser/check_flag.c
int				check_algorithm_flag(char *str);
char			get_algorithm(char *str);

// parser/init.c
int				is_valid_argument(t_node *stack, char *arg, long val);
t_node			*build_stack(char **argv, int start);
int				parse_flags(char **argv, char *flag);

// parser/number_check.c
int				is_valid_number(char *str);
int				check_int_limit(char *str);

// parser/print_error.c
void			print_error_exit(void);

// sort/run_sort.c
void			run_sort(t_node **stack_a, t_node **stack_b, char flag);

// stack/index.c
void			reindex(t_node *stack);
void			normalize_stack(t_node *stack);
t_node			*node_at(t_node *stack, int index);
int				index_of(t_node *stack, int value);
int				signed_distance(int pos, int size);

// stack/list.c
t_node			*new_node(int value);
void			push_top(t_node **stack, t_node *node);
t_node			*get_last(t_node *stack);
void			add_back(t_node **stack, t_node *node);
void			free_stack(t_node **stack);

// stack/stack.c
int				stack_size(t_node *stack);
int				stack_max(t_node *stack);
void			swap_first_two(t_node **stack);
int				is_sorted(t_node *stack);

// stack/stack_more.c
int				peek(t_node *stack);
t_node			*pop_top(t_node **stack);
void			shiftup(t_node **stack);
void			shiftdown(t_node **stack);

// utils/bench_utils.c
t_bench			*get_bench(void);
t_operations	*get_operations(void);

// utils/math.c
int				int_sqrt_ceil(int n);

#endif