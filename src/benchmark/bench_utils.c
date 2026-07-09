// header 

#include "pushswap.h"

t_bench	*get_bench(void)
{
	static t_bench	bench = {FALSE, 0, 0.0, "Adaptive"};
	return (&bench);
}

t_operations	*get_operations(void) 
{
    static t_operations	ops = {0};
    return (&ops);
}
