# NAME PROGRAM #
NAME	= game

# LIBFT #
LIB		= ./libft/libft.a
LIB_D	= ./libft

# SOURCE.C #
SRC		= map_validation.c teste.c so_long.c main.c
# COMPILING VARIABLES #
CC		= cc
CFLAG	= -Wall -Wextra -Werror
RM		= rm -f
CFLONG	= -Lmlx -lmlx -framework OpenGL -framework Appkit

$(NAME) : $(SRC)
	Make -C ./libft	
	$(CC) -g $(CFLAG) $(SRC) $(LIB) $(CFLONG) -o game

all:	$(NAME)

clean:
	$(MAKE) fclean -C $(LIB_D)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
