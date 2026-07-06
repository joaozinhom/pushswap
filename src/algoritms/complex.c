
#include "pushswap.h"

void get_to_index(t_node **stack, int index)
{
	int pos;
	int size;

	pos = index_of(*stack, index);
	size = stack_size(*stack);
	if (pos <= size / 2)
		while (pos-- > 0)
			ra(stack);
	else
		while (pos++ < size)
			rra(stack);
}

int find_pivot(t_node *a, int size)
{
    int i;
    int min;
    int max;

    i = 0;
    min = a->value;
    max = a->value;
    while (i < size)
    {
        if (a->value < min)
            min = a->value;
        if (a->value > max)
            max = a->value;
        a = a->next;
        i++;
    }
    return ((min + max) / 2);
}

int partition(t_node **a, t_node **b, int size)
{
    int pivot_value;
    int i;
    int count_below;

    pivot_value = find_pivot(*a, size);
    i = 0;
    count_below = 0;
    while (i < size)
    {
        if ((*a)->value < pivot_value)
        {
            pb(b, a);
            count_below++;
        }
        else
            ra(a);
        i++;
    }
    return (count_below);
}

void quick_sort(t_node **a, t_node **b, int size)
{
    int count_below;
    int i;

    if (size <= 1)
        return;
    count_below = partition(a, b, size);
    quick_sort(a, b, size - count_below);
    i = count_below;
    while (i-- > 0)
        pa(a, b);
    quick_sort(a, b, count_below);
}