#include "ft_printf.h"

#include "ft_printf.h"

int	ft_manager(char flag, va_list *args)
{
	if (flag == 'c')
		return (flag_c(va_arg(*args, int)));
	else if (flag == 'd')
		return (flag_d(va_arg(*args, int)));
	else if (flag == 'i')
		return (flag_i(va_arg(*args, int)));
	else if (flag == 'p')
		return (flag_p(va_arg(*args, void *)));
	else if (flag == '%')
		return (flag_percent());
	else if (flag == 's')
		return (flag_s(va_arg(*args, char *)));
	else if (flag == 'u')
		return (flag_u(va_arg(*args, unsigned int)));
	else if (flag == 'X')
		return (flag_upper_x(va_arg(*args, unsigned int)));
	else if (flag == 'x')
		return (flag_x(va_arg(*args, unsigned int)));
	else
		return (0);
}
