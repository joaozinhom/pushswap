#include "ft_printf.h"

int	flag_p(void *pointer)
{
	int	i;

	i = 0;
	i += write(1, "0x", 2);
	i += (ft_puthexdecimal((unsigned long)(pointer), 1, 1));
	return (i);
}
