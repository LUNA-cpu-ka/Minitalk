RED = "\033[0;31m"
YELLOW = "\033[0;33m"
MAGENTA= "\033[1;35m"
CYAN = "\033[36m"
GREEN0= "\033[32m"
RED = "\033[0;31m"

FLAGSS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client 
NAME = $(CLIENT) $(SERVER)
PRINTF = libftprintf.a

all: $(NAME)

$(NAME): $(PRINTF)
	@cc $(FLAGSS) server.c -o $(SERVER)
	@cc $(FLAGSS) client.c -o $(CLIENT)
	@echo $(GREEN0)Try this is it works

$(PRINTF):
	@echo $(RED) making pri 
	@make -C pri 
	@mv pri/libftprintf.a .

clean:
	@echo $(RED) remove obj printf
	@make -C pri clean
	rm -rf $(PRINTF)

fclean: clean
	@rm -rf $(SERVER) $(CLIENT) $(PRINTF)
	@echo $(YELLOW)the obj removed

re: fclean all

.PHONY: all clean fclean re