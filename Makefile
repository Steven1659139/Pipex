
NAME := pipex

CC := gcc 

FLAG :=  -Wall -Wextra -Werror

RM := rm -rfv

SRC := main.c pipe.c utils.c redirection.c

OBJ := $(SRC:.c=.o)

all : ${NAME}

$(NAME): ${OBJ}
		@echo "Compilation..."
	    @$(MAKE) -C ./Libft	
	    ${CC} ${OBJ} ${FLAG} ./Libft/libft.a -o ${NAME}
		

clean:
		@echo "Nettoyage..."
		@$(MAKE) -C  Libft fclean
		${RM} ${OBJ}
		
fclean: clean
		@echo "Réinitialisation..."
		${RM} ${NAME}

re: fclean all
	@echo "On scrap toute et on recommence..."


