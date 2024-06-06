
#Variables:
CC = cc
CFLAGSS = -Wall -Wextra -Werror

#Files:
SERVER = server
CLIENT = client
NAME = $(CLIENT) $(SERVER)

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

.SILENT: all clean fclean re