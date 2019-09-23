# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 14:54:25 by ppepperm          #+#    #+#              #
#    Updated: 2019/09/22 14:54:33 by ppepperm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit
SRC= main.c get_next_line.c get_next_line.h -I . -L libft/ -lft

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) $(SRC)

fclean:
	rm -f $(NAME)

re: fclean all