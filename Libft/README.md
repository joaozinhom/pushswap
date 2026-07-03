*This project has been created as part of the 42 curriculum by mpinto-l* 

## Libft

## Description 
The aim of this project is to code a C library regrouping usual functions that we'll be allowed to use in all our other projects. At 42 we are not allowed to use standard C library functions — we can only use functions we coded ourselves. So the longer term goal of this library is to grow with our own functions.

libft is the very first project of the 42 cursus. Here we reimplement a bunch of standard C functions from scratch, plus some extra utilities that aren't in libc. Everything gets compiled into a static archive `libft.a` that we'll keep reusing throughout the whole curriculum.

## Instructions
### Compilation 
```bash
cd libft
make 
```
This generates the `libft.a` static library at the root of the repository 

### Makefile rules 
| Rule | Description |
|------|-------------|
| `make` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and `libft.a` |
| `make re` | Runs `fclean` + `make` |

---

## Library 
### Part 1 — Libc functions

  

Reimplementations of standard C library functions, prefixed with `ft_`:

  

| Function | Description |
| ---------- |-------------|
| [ft_isalpha](ft_isalpha.c) | Checks if a character is alphabetic |
| [ft_isdigit](ft_isdigit.c) | Checks if a character is a digit |
| [ft_isalnum](ft_isalnum.c) | Checks if a character is alphanumeric |
| [ft_isascii](ft_isascii.c) | Checks if a character is in the ASCII table |
| [ft_isprint](ft_isprint.c) | Checks if a character is printable |
| [ft_strlen](ft_strlen.c) | Returns the length of a string |
| [ft_memset](ft_memset.c) | Fills a memory area with a constant byte |
| [ft_bzero](ft_bzero.c) | Sets a memory area to zero |
| [ft_memcpy](ft_memcpy.c) | Copies a memory area |
| [ft_memmove](ft_memmove.c) | Copies a memory area, handling overlaps |
| [ft_strlcpy](ft_strlcpy.c) | Size-bounded string copy |
| [ft_strlcat](ft_strlcat.c) | Size-bounded string concatenation |
| [ft_toupper](ft_toupper.c) | Converts a character to uppercase |
| [ft_tolower](ft_tolower.c) | Converts a character to lowercase |
| [ft_strchr](ft_strchr.c) | Locates a character in a string |
| [ft_strrchr](ft_strrchr.c) | Locates a character in a string (from the end) |
| [ft_strncmp](ft_strncmp.c) | Compares two strings up to n bytes |
| [ft_memchr](ft_memchr.c) | Scans memory for a character |
| [ft_memcmp](ft_memcmp.c) | Compares two memory areas |
| [ft_strnstr](ft_strnstr.c) | Locates a substring in a string |
| [ft_atoi](ft_atoi.c) | Converts a string to an integer |
| [ft_calloc](ft_calloc.c) | Allocates zero-initialized memory |
| [ft_strdup](ft_strdup.c) | Duplicates a string |


  ---

### Part 2 — Additional functions

  

Custom utility functions not present in the standard library:

  

| Function | Description |
|----------|-------------|
| [ft_substr](ft_substr.c) | Extracts a substring from a string |
| [ft_strjoin](ft_strjoin.c) | Concatenates two strings into a new one |
| [ft_strtrim](ft_strtrim.c) | Trims characters from both ends of a string |
| [ft_split](ft_split.c) | Splits a string by a delimiter character |
| [ft_itoa](ft_itoa.c) | Converts an integer to a string |
| [ft_strmapi](ft_strmapi.c) | Applies a function to each character, returning a new string |
| [ft_striteri](ft_striteri.c) | Applies a function to each character in-place |
| [ft_putchar_fd](ft_putchar_fd.c) | Outputs a character to a file descriptor |
| [ft_putstr_fd](ft_putstr_fd.c) | Outputs a string to a file descriptor |
| [ft_putendl_fd](ft_putendl_fd.c) | Outputs a string followed by a newline to a file descriptor |
| [ft_putnbr_fd](ft_putnbr_fd.c) | Outputs an integer to a file descriptor |

  ---

### Part 3 — Linked list functions

  

Functions to manipulate linked lists using the `t_list` structure:

  

```c

typedef  struct s_list

{

	void 			*content;

	struct s_list 	*next;

} 			t_list;

```

  

| Function | Description |
|----------|-------------|
| [ft_lstnew](ft_lstnew.c) | Creates a new list node |
| [ft_lstadd_front](ft_lstadd_front.c) | Adds a node at the beginning of the list |
| [ft_lstsize](ft_lstsize.c) | Returns the number of nodes in the list |
| [ft_lstlast](ft_lstlast.c) | Returns the last node of the list |
| [ft_lstadd_back](ft_lstadd_back.c) | Adds a node at the end of the list |
| [ft_lstdelone](ft_lstdelone.c) | Frees a single node's content and the node itself |
| [ft_lstclear](ft_lstclear.c) | Frees all nodes of the list |
| [ft_lstiter](ft_lstiter.c) | Applies a function to each node's content |
| [ft_lstmap](ft_lstmap.c) | Creates a new list by applying a function to each node |

  

---

## Resources 

-Man 3 (function name) - all Lib C

-[Libft-god](https://github.com/PLEB42/libft-god)

-[Makefile Tutor](https://github.com/clementvidon/Makefile_tutor)

-[Portfolio Courses](https://www.youtube.com/@PortfolioCourses)

-[Linked lists for absolute beginners](https://youtube.com/playlist?list=PLfqABt5AS4FmXeWuuNDS3XGENJO1VYGxl)

-[README.md - stackedit](https://stackedit.io/)


**AI usage:** During the implementation of the C functions, [Claude](claude.ai) was used as a learning aid — configured to explain concepts and point out what was wrong rather than provide direct answers.
