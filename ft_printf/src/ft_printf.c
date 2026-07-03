#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			i += ft_manager(*format, &args);
		}
		else
		{
			write(1, format, 1);
			i++;
		}
		format++;
	}
	va_end(args);
	return (i);
}
