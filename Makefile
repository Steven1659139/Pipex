NAME = pipex.a

LIBFT = Libft/libft.a

MAIN := main.c

OBJ_MAIN := $(MAIN:.c=.o)

SRC := utils.c redirection.c pipe.c

OBJ := $(SRC:.c=.o)

OBJ_WITH_MAIN := $(OBJ) $(OBJ_MAIN) $(LIBFT)
