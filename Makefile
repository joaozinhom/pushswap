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
		algorithms/complex.c \
		algorithms/medium.c \
		algorithms/simple.c \
		benchmark/bench.c \
		benchmark/bench_utils.c \
		benchmark/disorder.c \
		benchmark/operations.c \
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
		parser/check_flag.c \
		parser/init.c \
		parser/number_check.c \
		sort/run_sort.c\
		parser/print_error.c \
		stack/index.c \
		stack/list.c \
		stack/stack.c \
		stack/stack_more.c \
		utils/math.c \
		utils/medium_utils.c


	

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