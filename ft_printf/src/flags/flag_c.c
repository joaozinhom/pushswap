#include "ft_printf.h"

int	flag_c(char c)
{
	write(1, &c, 1);
	return (1);
}
