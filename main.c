#include "pushswap.h"
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

static int	parse_long(const char *s, long *out)
{
	char	*end;
	long	val;

	errno = 0;
	val = strtol(s, &end, 10);
	if (*s == '\0' || *end != '\0')
		return (0);
	if (errno == ERANGE || val > INT_MAX || val < INT_MIN)
		return (0);
	*out = val;
	return (1);
}

static int	has_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

/* NOTE: is_sorted() is declared in pushswap.h but not implemented anywhere
 * in your tree (checked stack.c). Using a local stand-in here so the test
 * can run — you need to add a real is_sorted() to stack.c. */
static int	test_is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	print_stack(t_node *stack)
{
	printf("[");
	while (stack)
	{
		printf("%d", stack->value);
		if (stack->next)
			printf(" ");
		stack = stack->next;
	}
	printf("]\n");
}

int	main(int argc, char **argv)
{
	t_node	*stack;
	long	val;
	size_t	ops;
	int		i;

	if (argc < 2)
	{
		printf("Usage: %s <int> <int> ...\n", argv[0]);
		return (0);
	}
	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (!parse_long(argv[i], &val) || has_duplicate(stack, (int)val))
		{
			fprintf(stderr, "Error\n");
			free_stack(&stack);
			return (1);
		}
		add_back(&stack, new_node((int)val));
		i++;
	}
	printf("before: ");
	print_stack(stack);
	ops = bubble_sorting(&stack);
	printf("after:  ");
	print_stack(stack);
	printf("ops:    %zu\n", ops);
	printf("sorted: %s\n", test_is_sorted(stack) ? "YES" : "NO");
	free_stack(&stack);
	return (0);
}