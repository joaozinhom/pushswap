*This project has been created as part of the 42 curriculum by mpinto-l*

## ft_printf()

## Description

At 42 we can't use `printf()`, so we have to build our own. `ft_printf` is a reimplementation of the standard C `printf()` that handles the most common format specifiers: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`. It gets compiled into a static library `libftprintf.a` that we can reuse in future projects.

### Algorithm and Data Structure

`ft_printf` reads the format string one character at a time. Normal characters get printed as-is. When it finds a `%`, it checks the next character and calls the right function — `ft_putchar` for `%c`, `ft_putstr` for `%s`, and so on. Each function prints its value and returns how many characters it wrote, which all adds up to the final return value.

Number printing uses recursion: divide the number by 10 (or 16 for hex) until there's a single digit left, then print on the way back up. `ft_putnbr` has a special case for `INT_MIN` since negating it would overflow. NULL pointers print as `(null)` or `(nil)` to match the original `printf`.

## Instructions

### Compilation

```bash
cd ft_printf
make
```

This generates `libftprintf.a`.

### Makefile rules

| Rule | Description |
|------|-------------|
| `make` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libftprintf.a` |
| `make re` | Runs `fclean` + `make` |

### Usage

Link `libftprintf.a` into your project:

```bash
cc main.c -L. -lftprintf -o program
```

## Functions

| Function | File | Description |
|----------|------|-------------|
| `ft_printf` | [src/ft_printf.c](src/ft_printf.c) | Main function. Reads the format string and calls the right function for each `%` |
| `check_format` | [src/ft_printf.c](src/ft_printf.c) | Checks which specifier was given and calls the matching print function |
| `ft_putchar` | [src/ft_putchar.c](src/ft_putchar.c) | Prints a single character |
| `ft_putstr` | [src/ft_putstr.c](src/ft_putstr.c) | Prints a string. Prints `(null)` if the string is NULL |
| `ft_putnbr` | [src/ft_putnbr.c](src/ft_putnbr.c) | Prints a signed integer |
| `ft_putnbr_unsigned` | [src/ft_putnbr_unsigned.c](src/ft_putnbr_unsigned.c) | Prints an unsigned integer |
| `ft_puthex_lower` | [src/ft_puthex_lower.c](src/ft_puthex_lower.c) | Prints a number in hexadecimal lowercase (`%x`) |
| `ft_puthex_upper` | [src/ft_puthex_upper.c](src/ft_puthex_upper.c) | Prints a number in hexadecimal uppercase (`%X`) |
| `ft_putadress` | [src/ft_flag_p.c](src/ft_flag_p.c) | Prints a memory address in hexadecimal |
| `ft_putpointer` | [src/ft_flag_p.c](src/ft_flag_p.c) | Prints a pointer with `0x` prefix. Prints `(nil)` if the pointer is NULL |

## Resources

- [What are variadic functions (va_list) in C?](https://www.youtube.com/watch?app=desktop&v=oDC208zvsdg)
- [Variadic Functions — DigiPen](https://azrael.digipen.edu/~mmead/www/Courses/CS120/VariadicFunctions.html)
- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html)

### AI Usage

AI usage: During the implementation of the C functions, Claude was used as a learning aid.


