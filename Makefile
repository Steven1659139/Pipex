NAME := pipex

CC := gcc
CFLAGS := -Wall -Werror -Wextra

RM := rm -rfv

SRCS := pipex.c utils.c
OBJS := $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	@echo "Compilation de $(NAME)"
	@$(MAKE) -C ./Libft
	$(CC) $(CFLAGS) $(OBJS) ./Libft/libft.a -o $(NAME)

clean:
	@echo "Nettoyage..."
	@$(MAKE) -C  Libft fclean
	${RM} ${OBJS}

fclean: clean
	@echo "Supression de l'executable"
	${RM} ${NAME}

re: fclean all
