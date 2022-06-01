# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 14:40:54 by blaurent          #+#    #+#              #
#    Updated: 2022/06/01 12:40:20 by blaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

FLAGS		= -Wall -Wextra -Werror

FILES		= pipex.c \
				pipex_utils.c \

OBJ 		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./mylib
	cp mylib/mylib.a $(NAME)
	@ar crs $(NAME) $(OBJ)
	chmod 777 pipex 

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make clean -C mylib/
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C mylib/
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re