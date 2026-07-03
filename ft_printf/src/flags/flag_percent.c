#include "ft_printf.h"

int	flag_percent(void)
{
	write(1, "%", 1);
	return (1);
}
