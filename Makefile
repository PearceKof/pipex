# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blaurent <blaurent@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/26 14:40:54 by blaurent          #+#    #+#              #
#    Updated: 2022/06/01 16:51:15 by blaurent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

FLAGS		= -Wall -Wextra -Werror

FILES		= pipex.c \
				utils.c \
				mylib/libft/ft_bzero.c \
				mylib/libft/ft_calloc.c \
				mylib/libft/ft_freetab.c \
				mylib/libft/ft_itoa.c \
				mylib/libft/ft_putaddr.c \
				mylib/libft/ft_putchar_fd.c \
				mylib/libft/ft_putendl_fd.c \
				mylib/libft/ft_putnbr_base.c \
				mylib/libft/ft_putnbr_fd.c \
				mylib/libft/ft_putstr_fd.c \
				mylib/libft/ft_split.c \
				mylib/libft/ft_strjoin.c \
				mylib/libft/ft_strlen.c \
				mylib/libft/ft_strstr.c \
				mylib/libft/ft_strdup.c \
				mylib/ft_fprintf/ft_fprintf.c \
				mylib/ft_fprintf/ft_fprint_c.c \
				mylib/ft_fprintf/ft_fprint_p.c \
				mylib/ft_fprintf/ft_fprint_s.c \
				mylib/ft_fprintf/ft_fprint_u.c \
				mylib/ft_fprintf/ft_fprint_x.c \
				mylib/ft_fprintf/ft_fprint_di.c \

OBJ			= $(FILES:%.c=%.o)

all: $(OBJ) $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

%.o: %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re