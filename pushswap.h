#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../Libft/libft.h"
# include "../ft_printf/ft_printf.h"


//bench 

typedef struct s_operations // conta a quantidade de operacoes
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;

} t_operations;

typedef struct s_bench
{
	int		total;
	int		complexity;
	double	disorder;
	char	*strategy;

} t_bench;

	// count-ops.c

	t_operations *get_operations(void);
	void print_op(char *op);
	void	print_op_name(char *name);



// 

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
}   t_node;


size_t  bubble_sorting(t_node **stack);
int     chunk_sorting(t_node **stack_a, t_node **stack_b);
double  disorder_metric(t_node *stack);


// medium.c
int		int_sqrt_ceil(int n);
int		find_insert_pos(t_node *stack_b, int value);
void	rotate_b_to(t_node **stack_b, int pos, int size_b);
void	insert_sorted_b(t_node **stack_a, t_node **stack_b);
void	push_chunk(t_node **stack_a, t_node **stack_b, int start, int end);
int		chunk_sorting(t_node **stack_a, t_node **stack_b);

// index.c
void	reindex(t_node *stack);
t_node	*node_at(t_node *stack, int index);
int		index_of(t_node *stack, int value);
int		signed_distance(int pos, int size);

// list.c
t_node  *new_node(int value);
void    push_top(t_node **stack, t_node *node);
t_node  *get_last(t_node *stack);
void    add_back(t_node **stack, t_node *node);
void    free_stack(t_node **stack);

// stack.c
int     stack_size(t_node *stack);
t_node  *pop_top(t_node **stack);
int     is_sorted(t_node *stack);
int     stack_max(t_node *stack);
int     peek(t_node *stack);
void    swap_first_two(t_node **stack);
void    shiftdown(t_node **stack);
void    shiftup(t_node **stack);

// operators
void    sa(t_node **stack);
void    sb(t_node **stack);
void    ss(t_node **stack_a, t_node **stack_b);
void    pa(t_node **stack_a, t_node **stack_b);
void    pb(t_node **stack_b, t_node **stack_a);
void    ra(t_node **stack_a);
void    rb(t_node **stack_b);
void    rr(t_node **stack_a, t_node **stack_b);
void    rra(t_node **stack_a);
void    rrb(t_node **stack_b);
void    rrr(t_node **stack_a, t_node **stack_b);

// parser 

    // error\n 

void    print_error_exit(void);
   
    // number check
int     is_valid_number(char *str);
int     check_int_limit(char *str);

    // check flags 

int     check_algorithm_flag(char *str);
char    get_algorithm(char *str);  

    //init
int     is_valid_argument(t_node *stack, char *arg, long val);
t_node	*build_stack(char **argv, int start);
int     parse_flags(char **argv, char *flag, int *bench);
void    run_sort(t_node **stack_a, t_node **stack_b, char flag);



#endif