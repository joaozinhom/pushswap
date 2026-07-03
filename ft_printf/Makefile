NAME    = libftprintf.a
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
AR      = ar rcs
RM      = rm -f

SRCS    =   src/ft_printf.c \
            src/manager.c \
            src/flags/flag_i.c \
            src/flags/flag_x.c \
            src/flags/flag_upper_x.c \
            src/flags/flag_percent.c \
            src/flags/flag_d.c \
            src/flags/flag_c.c \
            src/flags/flag_s.c \
            src/flags/flag_u.c \
            src/flags/flag_p.c \
            src/utils/putdecimal.c \
            src/utils/puthexadecimal.c \
            src/utils/ft_strlen.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re