RED = "\033[0;31m"
GREEN0= "\033[32m"
RED = "\033[0;31m"
BLUE = "\033[34m"

FLAGSS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client
NAME = $(CLIENT) $(SERVER)
PRINTF = libftprintf.a

all: $(NAME)

$(NAME): $(PRINTF)
	@echo $(NOT)$(BLUE) Making server and client ⚙️ ...
	@cc $(FLAGSS) server.c $(PRINTF) -o $(SERVER)
	@cc $(FLAGSS) client.c $(PRINTF) -o $(CLIENT)

$(PRINTF):
	@echo $(BLUE) Making printf ⚙️ ...
	@make -C pri 
	@mv pri/libftprintf.a .

clean:
	@echo $(RED) Removing printf"'"s object files 👾👾👾 ...
	@make -C pri clean
	@rm -rf $(PRINTF)

fclean: clean
	@rm -rf $(SERVER) $(CLIENT) $(PRINTF)
	@echo $(RED) Removing minitalk"'"s object files 👾 ...
	@echo $(GREEN0) ✨ Done cleaning ✨

re: fclean all

.PHONY: all clean fclean re