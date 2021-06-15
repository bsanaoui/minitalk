.PHONY: all fclean clean re bonus
NAME = minitalk
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
BONUS = bonus
CC = gcc
FLAGS = -Werror -Wextra -Wall

SRC= utils.c utils_libft.c
SRC_BONUS= bonus_minitalk/utils_bonus.c bonus_minitalk/utils_libft_bonus.c bonus_minitalk/ft_itoa_bonus.c

all : $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT):
	@$(CC) client.c  $(SRC) -I $(FLAGS) -o $(CLIENT)

$(SERVER):
	@$(CC) server.c $(SRC) -I $(FLAGS) -o $(SERVER)

$(CLIENT_BONUS):
	@$(CC) bonus_minitalk/client_bonus.c  $(SRC_BONUS) -I $(FLAGS) -o $(CLIENT_BONUS)

$(SERVER_BONUS):
	@$(CC) bonus_minitalk/server_bonus.c $(SRC_BONUS) -I $(FLAGS) -o $(SERVER_BONUS)

$(BONUS): $(CLIENT_BONUS) $(SERVER_BONUS)

fclean: clean
	@rm -f $(CLIENT) $(SERVER) $(CLIENT_BONUS) $(SERVER_BONUS)

clean:
	@rm -f *.o

re: fclean all