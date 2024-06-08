
#Variables:
CC = cc
CFLAGSS = -Wall -Wextra -Werror

#Files:
SERVER = server
CLIENT = client

SBERVER = server_bonus
CBLIENT = client_bonus
NBAME = $(CBLIENT) $(SBERVER)

SSRC= server.c
CSRC= client.c functions.c

#Libarary:
PRINTF = libftprintf.a

#Colors:
RED = "\033[0;31m"
GREEN0 = "\033[32m"
RED = "\033[0;31m"
BLUE = "\033[34m"

SOBJ=$(SSRC:.c=.o)
COBJ=$(CSRC:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(SOBJ) $(PRINTF)
	@$(CC) $(CFLAGSS) $(SOBJ) $(PRINTF) -o $(SERVER)
	@echo $(BLUE) Making server ⚙️ ...

$(CLIENT): $(COBJ) $(PRINTF)
	@$(CC) $(CFLAGSS) $(COBJ) $(PRINTF) -o $(CLIENT)
	@echo $(BLUE) Making client ⚙️ ...

bonus: $(NBAME) $(PRINTF)

$(NBAME): $(PRINTF)
	@$(CC) $(CFLAGSS) server_bonus.c $(PRINTF) -o $(SBERVER)
	@$(CC) $(CFLAGSS) client_bonus.c functions.c  $(PRINTF) -o $(CBLIENT)
	@echo $(BLUE) Making bonus ⚙️ ...

$(PRINTF):
	@make -C pri 
	@mv pri/libftprintf.a .
	@echo $(BLUE) Making printf ⚙️ ...
	
clean:
	@echo $(RED) Removing object files 👾 ...
	@make -C pri clean
	@rm -rf $(PRINTF) $(SOBJ) $(COBJ)

fclean: clean
	@rm -rf $(SERVER) $(CLIENT) $(PRINTF) $(SBERVER) $(CBLIENT)
	@echo $(RED) Removing all 👾 ...
	@echo $(GREEN0) ✨ Done cleaning ✨

re: fclean all bonus

.SILENT: all clean fclean re
