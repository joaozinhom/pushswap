NAME		:= push_swap

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM			:= rm -rf

SRC_DIR		:= src
OBJ_DIR		:= obj
INC_DIR		:= .

LIBFT_DIR	:= Libft
LIBFT		:= $(LIBFT_DIR)/libft.a

PRINTF_DIR	:= ft_printf
PRINTF_LIB	:= $(PRINTF_DIR)/libftprintf.a

# not compiled yet: puswap.c, algoritms/complex.c (WIP), algoritms/adaptative.c (empty)
SRCS        :=	\
		main.c \
		benchmarks/disorder_metric.c \
		algoritms/simple.c \
		algoritms/medium.c \
		operators/pa.c \
		operators/pb.c \
		operators/ra.c \
		operators/rb.c \
		operators/rra.c \
		operators/rrb.c \
		operators/rr.c \
		operators/rrr.c \
		operators/sa.c \
		operators/sb.c \
		operators/ss.c \
		utils/list.c \
		utils/stack.c \
		utils/index.c \
		parser/check_flag.c\
		parser/init.c\
		parser/number_check.c\
		parser/print_error.c\
		utils/math_operators.c
	

OBJS        := $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

INCLUDES	:= -I $(INC_DIR) -I $(LIBFT_DIR) -I $(PRINTF_DIR)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF_LIB)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF_LIB) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_LIB):
	$(MAKE) -C $(PRINTF_DIR)
clean:
	$(RM) $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
 
fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re $(LIBFT_DIR) $(PRINTF_DIR)
.SILENT: