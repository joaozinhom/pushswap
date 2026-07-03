NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDES	= -I.

SRCS		= main.c \
			  src/puswap.c \
			  src/benchmarks/disorder_metric.c \
			  src/algoritms/adaptative.c \
			  src/algoritms/complex.c \
			  src/algoritms/medium.c \
			  src/algoritms/simple.c \
			  src/operators/sa.c \
			  src/operators/sb.c \
			  src/operators/ss.c \
			  src/operators/pa.c \
			  src/operators/pb.c \
			  src/operators/ra.c \
			  src/operators/rb.c \
			  src/operators/rr.c \
			  src/operators/rra.c \
			  src/operators/rrb.c \
			  src/operators/rrr.c \
			  src/utils/list.c \
			  src/utils/stack.c

OBJS		= $(SRCS:.c=.o)

HEADER		= pushswap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
