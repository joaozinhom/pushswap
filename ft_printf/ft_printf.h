#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		flag_i(int i);
int		flag_x(unsigned int i);
int		flag_upper_x(unsigned int i);
int		flag_percent(void);
int		flag_d(int n);
int		flag_c(char c);
int		flag_s(char *s);
int		flag_u(unsigned int i);
int		flag_p(void *pointer);
int		ft_putdecimal(int n, int fd);
int		putunsigneddecimal(unsigned long n, int fd);
int		ft_puthexdecimal(unsigned long n, int fd, int islower);
size_t	ft_strlen(const char *s);
int		ft_manager(char flag, va_list *args);
int		ft_printf(const char *format, ...);
#endif