RED = "\033[0;31m"
YELLOW = "\033[0;33m"
MAGENTA= "\033[1;35m"
CYAN = "\033[36m"
GREEN0= "\033[32m"

FLAGSS = -Wall -Wextra -Werror
SERVER = server
CLIENT = client 
NAME = $(CLIENT) $(SERVER)

all: $(NAME)

	@cc $(FLAGSS) server.c -o $(SERVER)
	@cc $(FLAGSS) client.c -o $(CLIENT)
	@echo $(GREEN0)Try this is it works

clean:
	@echo $(CYAN) Do not forget to add the ft_printf

fclean:
	@rm -rf $(SERVER) $(CLIENT)
	@echo $(YELLOW)the obj removed

re: fclean all

.PHONY: all clean fclean re