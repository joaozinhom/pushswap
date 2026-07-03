#include "ft_printf.h"

int	flag_upper_x(unsigned int i)
{
	return (ft_puthexdecimal((unsigned long)i, 1, 0));
}
