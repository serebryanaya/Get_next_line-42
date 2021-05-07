NAME = get_next_line.a

SRCS = get_next_line.c

OBJS = $(SRCS:.c=.o)

CC	= cc

CFLAGS	= -Wall -Wextra -Werror -D BUFFER_SIZE=32

.c.o:	get_next_line.h
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
		ar rc $(NAME) $(OBJS)

RM	= rm -f
			
clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re