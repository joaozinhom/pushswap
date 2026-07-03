#include "ft_printf.h"

int	flag_s(char *s)
{
	if (!s)
		s = "(null)";
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}
