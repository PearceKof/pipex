# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/12 17:03:42 by blaurent          #+#    #+#              #
#    Updated: 2022/07/12 17:03:42 by blaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 		= libft.a

FLAGS		= -Wall -Wextra -Werror

FILES 		=	ft_bzero.c \
						ft_calloc.c \
						ft_freetab.c \
						ft_itoa.c \
						ft_putaddr.c \
						ft_putchar_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_base.c \
						ft_putnbr_fd.c \
						ft_putstr_fd.c \
						ft_split.c \
						ft_strjoin.c \
						ft_strlen.c \
						ft_strstr.c \

OBJ 		= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar crs $(NAME) $(OBJ)

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re