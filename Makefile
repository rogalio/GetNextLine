SRCS		:= $(wildcard *.c)

OBJS=		$(SRCS:.c=.o)

RM=		rm -f

CFLAGS=		-g3

NAME=		gnl

CC=		gcc

all:	 $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $^

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re bonus
