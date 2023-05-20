SRCS = get_next_line.c get_next_line_utils.c \
OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
RM = rm -f

NAME = gnl.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
