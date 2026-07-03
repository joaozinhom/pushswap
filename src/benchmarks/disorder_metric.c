#include "pushswap.h"

/*
function compute_disorder(stack a):
mistakes = 0
total_pairs = 0
for i from 0 to size(a)-1:
for j from i+1 to size(a)-1:
total_pairs += 1
if a[i] > a[j]:
mistakes += 1
return mistakes / total_pairs
*/
double disorder_metric(t_node *stack)
{
    t_node  *i;
    t_node  *j;
    size_t  mistakes;
    size_t  total_pairs;

    mistakes = 0;
    total_pairs = 0;
    i = stack;
    while (i != NULL)
    {
        j = i->next;
        while (j != NULL)
        {
            if (i->value > j->value)
                mistakes++;
            total_pairs++;
            j = j->next;
        }
        i = i->next;
    }
    if (total_pairs == 0)
        return (0.0);
    return ((double)mistakes / (double)total_pairs);
}
