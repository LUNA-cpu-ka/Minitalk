
#Variables:
CC = cc
CFLAGSS = -Wall -Wextra -Werror

#Files:
SERVER = server
CLIENT = client
NAME = $(CLIENT) $(SERVER)

SBERVER = server_bonus
CBLIENT = client_bonus
NBAME = $(CBLIENT) $(SBERVER)

#Libarary:
PRINTF = libftprintf.a

#Colors:
RED = "\033[0;31m"
GREEN0 = "\033[32m"
RED = "\033[0;31m"
BLUE = "\033[34m"


all: $(NAME) $(PRINTF)

$(NAME): $(PRINTF)
	@echo $(BLUE) Making server and client ⚙️ ...
	@$(CC) $(CFLAGSS) server.c $(PRINTF) -o $(SERVER)
	@$(CC) $(CFLAGSS) client.c functions.c  $(PRINTF) -o $(CLIENT)

bonus: $(NBAME) $(PRINTF)

$(NBAME): $(PRINTF)
	@echo $(BLUE) Making server and client bonus⚙️ ...
	@$(CC) $(CFLAGSS) server_bonus.c $(PRINTF) -o $(SBERVER)
	@$(CC) $(CFLAGSS) client_bonus.c functions.c  $(PRINTF) -o $(CBLIENT)

$(PRINTF):
	@echo $(BLUE) Making printf ⚙️ ...
	@make -C pri 
	@mv pri/libftprintf.a .

clean:
	@echo $(RED) Removing printf"'"s object files 👾👾👾 ...
	@make -C pri clean
	@rm -rf $(PRINTF)

fclean: clean
	@rm -rf $(SERVER) $(CLIENT) $(PRINTF) $(SBERVER) $(CBLIENT)
	@echo $(RED) Removing minitalk"'"s object files 👾 ...
	@echo $(GREEN0) ✨ Done cleaning ✨

re: fclean all bonus

.PHONY: all clean fclean re