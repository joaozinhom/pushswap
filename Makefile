NAME		:= push_swap

CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror
RM		:= rm -f

SRC_DIR		:= src
OBJ_DIR		:= obj
INC_DIR		:= .

SRCS        =	\
		main.c\
		puswap.c \
		disorder_metric.c \
		algoritms/simple.c \
		algoritms/medium.c \
		algoritms/complex.c \
		algoritms/adaptative.c \
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
		utils/stack.c

OBJS        = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

INCLUDES	:= -I $(INC_DIR)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p (dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@


clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: