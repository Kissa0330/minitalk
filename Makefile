NAME = minitalk
CLIENT_NAME = client
SERVER_NAME = server
SRCS = utils.c
CLIENT_SRCS = clients.c $(SRCS)
SERVER_SRCS = server.c $(SRCS)
CC = gcc
# CFLAGS = -Wall -Werror -Wextra

.PHONY : all clean fclean re

all: $(NAME)

$(NAME):
	make -C libft
	cp ./libft/libft.a .
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -L. -lft -o $(CLIENT_NAME)
	$(CC) $(CFLAGS) $(SERVER_SRCS) -L. -lft -o $(SERVER_NAME)

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -f libft.a
	rm -f $(CLIENT_NAME)
	rm -f $(SERVER_NAME)

re: fclean all