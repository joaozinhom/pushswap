NAME        = libftprintf.a

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
AR          = ar rcs

SRC_DIR     = src
OBJ_DIR     = obj
INC_DIR     = .

SRCS        = 	\
              ft_printf.c \
              ft_putchar.c \
              ft_putnbr.c \
              ft_putnbr_unsigned.c \
              ft_putstr.c \
              ft_puthex_lower.c \
              ft_puthex_upper.c \
              ft_flag_p.c 


OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

INCLUDES    = -I$(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)


clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: