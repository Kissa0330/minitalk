NAME = so_long
CLIENT_SRCS = clients.c
SERVER_SRCS = server.c
SRCS = utils.c
CC = gcc
# CFLAGS = -Wall -Werror -Wextra

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(SRCS)
	make -C libft
	cp ./libft/libft.a .
	$(CC) $(CFLAGS) $(CLIENT_SRCS) $(SRCS) -L. -lft -o client
	$(CC) $(CFLAGS) $(SERVER_SRCS) $(SRCS) -L. -lft -o server

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f libft.a
	rm -f $(NAME)

re: fclean all