.PHONY: all fclean clean re bonus
NAME = minitalk
CLIENT = client
SERVER = server
BONUS = bonus
CC = gcc
FLAGS = -Werror -Wextra -Wall

SRC_CLIENT = client.c utils.c utils_libft.c ft_itoa.c
SRC_SERVER = server.c utils.c utils_libft.c

all : $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT):
	@$(CC) $(SRC_CLIENT) -I $(FLAGS) -o $(CLIENT)

$(SERVER):
	@$(CC) $(SRC_SERVER) -I $(FLAGS) -o $(SERVER)


fclean: clean
	@rm -f $(CLIENT) $(SERVER) $(BONUS)

clean:
	@rm -f *.o

re: fclean all