NAME = minitalk
CLIENT_NAME = client
SERVER_NAME = server
CLIENT_SRCS = clients.c
SERVER_SRCS = server.c
CC = cc
CFLAGS = -Wall -Werror -Wextra

.PHONY : all clean fclean re

all: $(NAME)

$(NAME): $(CLIENT_NAME) $(SERVER_NAME)

$(CLIENT_NAME): $(CLIENT_SRCS)
	make -C libft
	cp ./libft/libft.a .
	$(CC) $(CFLAGS) $(CLIENT_SRCS) -L. -lft -o $(CLIENT_NAME)

$(SERVER_NAME): $(SERVER_SRCS)
	make -C libft
	cp ./libft/libft.a .
	$(CC) $(CFLAGS) $(SERVER_SRCS) -L. -lft -o $(SERVER_NAME)

clean:
	make -C libft clean

fclean: clean
	make -C libft fclean
	rm -f libft.a
	rm -f $(CLIENT_NAME)
	rm -f $(SERVER_NAME)

re: fclean all