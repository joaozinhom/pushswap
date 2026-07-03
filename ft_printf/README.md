*This project has been created as part of the 42 curriculum by joamoren.*

# ft_printf

## Description

ft_printf is a partial re-implementation of the C standard library printf(3). The goal is to understand how variadic functions work in C and how a format string is parsed and dispatched to type-specific output routines, without using any dynamic memory allocation in the core logic.

The library is compiled as a static archive (libftprintf.a) and depends on libft, the custom C utility library also developed during the 42 curriculum.

Supported conversions: %c (character), %s (string), %d and %i (signed decimal), %u (unsigned decimal), %x (hex lowercase), %X (hex uppercase), %p (pointer address), %% (literal percent).

The entry point is ft_printf.c, which contains the format string loop. manager.c dispatches each specifier to its handler in src/flags/. Shared numeric output routines live in src/utils/.

## Algorithm and Data Structure

ft_printf iterates over the format string one byte at a time with a while loop. Regular characters are written directly to stdout. When a % is found, the next byte is read as the specifier and passed to ft_manager. This is a linear scan, O(n) in the length of the format string, with no look-ahead beyond one character, which is enough since no supported specifier needs more than that.

The va_list is initialised with va_start before the loop and closed with va_end after. A pointer to the va_list is passed down to ft_manager and all flag functions so that every va_arg call advances the same internal cursor. Passing by value would copy the list state and reset the cursor on each call, which is undefined behaviour on most ABIs.

ft_manager is an if/else chain keyed on the specifier character. With only nine specifiers the linear cost is negligible, and the approach avoids function pointers or any lookup structure while staying readable.

Both ft_putdecimal and ft_puthexdecimal use recursion to print digits in the correct left-to-right order without a buffer. If n is greater than or equal to the base, the function recurses on n/base first, then writes n%base on the way back up the call stack. This naturally reverses the order in which remainders are produced. Stack depth is at most around 10 frames for decimal (log base 10 of 2^31) and 16 frames for hexadecimal (log base 16 of 2^64), both well within any reasonable stack limit.

The special case of INT_MIN (-2147483648) is handled explicitly before negation because -INT_MIN overflows a 32-bit signed integer.

ft_puthexdecimal and putunsigneddecimal accept unsigned long rather than unsigned int so that flag_p can pass a 64-bit pointer value on LP64 platforms (Linux x86-64, macOS arm64) without truncation. The flag-level functions widen their unsigned int argument on the call, which is a safe zero-extension.

## Instructions

Build the library:

    make

Remove object files:

    make clean

Remove object files and the archive:

    make fclean

Full rebuild:

    make re

To link the library into your own program:

    cc -Wall -Wextra -Werror your_program.c -L. -lftprintf -o your_program

The header ft_printf.h is at the root of the repository. Pass -I with the path to the repo if compiling from another directory.

## Resources

- https://www.w3schools.com/c/c_variables_format.php — format specifiers in C
- https://www.geeksforgeeks.org/c/printf-in-c/ — printf overview and usage
- https://www.geeksforgeeks.org/c/format-specifiers-in-c/ — format specifiers reference
- https://www.geeksforgeeks.org/c/variadic-functions-in-c/ — variadic functions and stdarg.h
- https://en.cppreference.com/w/c/io/fprintf — full conversion specifier specification
- https://en.cppreference.com/w/c/variadic/va_arg — va_arg and argument promotion rules

### AI usage

Claude (Anthropic) was used for search help and find some references.