.SILENT:

# Nom du projet
NAME := pipex

# Compilateur et options de compilation
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g

# Commandes de suppression avec verbosité
RM := rm -rfv

# Fichiers sources et objets
SRCS := pipex.c utils.c
OBJS := $(SRCS:.c=.o)

# Couleurs pour les messages
GREEN := \033[1;32m
YELLOW := \033[1;33m
RED := \033[1;31m
BLUE := \033[1;34m
RESET := \033[0m

# Règles de compilation
all : $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)🔨 Compilation de $(NAME)...$(RESET)"
	@$(MAKE) -C ./Libft
	$(CC) $(CFLAGS) $(OBJS) ./Libft/libft.a -o $(NAME)
	@echo "$(GREEN)✅ Compilation terminée avec succès !$(RESET)"

clean:
	@echo "$(YELLOW)🧹 Nettoyage des fichiers objets...$(RESET)"
	@$(MAKE) -C Libft fclean
	${RM} ${OBJS}
	@echo "$(GREEN)✅ Nettoyage terminé !$(RESET)"

fclean: clean
	@echo "$(RED)🚨 Suppression de l'exécutable $(NAME)...$(RESET)"
	${RM} ${NAME}
	@echo "$(GREEN)✅ Suppression terminée !$(RESET)"

re: fclean all
	@echo "$(BLUE)🔄 Recompilation complète de $(NAME)...$(RESET)"

