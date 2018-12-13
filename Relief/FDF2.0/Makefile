# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drestles <drestles@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/13 01:39:19 by drestles          #+#    #+#              #
#    Updated: 2018/12/13 03:50:22 by drestles         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
FLAG = -lmlx -framework OpenGL -framework Appkit
FLAGN = -Wall -Wextra -Werror

SRC = 	main.c \
		error.c \
		check_valid.c \
		parsing.c \
		window.c \
		image.c \

all: $(NAME)

$(NAME): $(SRC)
	@make -C libft
	@gcc -o $(NAME) $(SRC) $(FLAG) $(FLAGN) libft/libft.a
	@echo "\033[7;36m СКОМПИЛЕНО! \t\t\t\033[7;32m| OK |"

clean:
	@make -C libft clean

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)

re: fclean line all

.PHONY: all line fclean clean re
