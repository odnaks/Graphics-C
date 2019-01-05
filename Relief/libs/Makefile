NAME = libft.a
FUNCS = $(shell cat $(INCL_DIR)/libft.h | grep -Eo "ft_\w+")
SRCS = $(FUNCS:=.c)
INCL_DIR =../incl
OBJ = $(SRCS:%.c=%.o)
CC = gcc
FLAGS = -c -Wall -Werror -Wextra -I $(INCL_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ): $(SRCS)
	$(CC) $(FLAGS) $(SRCS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
