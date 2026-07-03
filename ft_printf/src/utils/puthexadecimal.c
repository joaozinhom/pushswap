#include "ft_printf.h"

int	ft_puthexdecimal(unsigned long n, int fd, int islower)
{
	unsigned long	num;
	int				i;
	char			*hex_digits;

	i = 0;
	num = n;
	if (islower)
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	if (num >= 16)
	{
		i += ft_puthexdecimal(num / 16, fd, islower);
	}
	i += write(fd, &hex_digits[num % 16], 1);
	return (i);
}
