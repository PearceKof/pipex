# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 14:40:54 by blaurent          #+#    #+#              #
#    Updated: 2022/05/26 14:41:36 by blaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

FLAGS		= -Wall -Wextra -Werror

FILES		=

OBJ 		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar crs $(NAME) $(OBJ)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@make clean -C libft/
	@rm -f $(OBJ) $(BOBJ)

fclean: clean
	@make fclean -C libft/
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re