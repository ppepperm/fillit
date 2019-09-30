# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ppepperm <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/22 14:54:25 by ppepperm          #+#    #+#              #
#    Updated: 2019/09/29 16:45:34 by snorcros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit
SRC := main.c list_ops.c read_ops.c copmare.c tab_ops.c tetris_ops.c
OBJ := $(patsubst %.c, %.o, $(SRC))

LIB_FLAG := -L libft/ -lft

all: $(NAME)

%.o : src/%.c $(INCLUDES)fillit.h
		@gcc -c $(CFLAGS) -I $(INCLUDES) $< -o $@
		@echo $(patsubst src/%.c, %, $<)

$(NAME): $(OBJ)
		@make -C libft
		@gcc -o $(NAME) -Wall -Wextra -Werror $(LIB_FLAG) $(OBJ)
		@echo "DONE"

clean:
		rm -f $(OBJ)
		make -C libft clean

fclean: clean
		rm -f $(NAME)
		make -C libft fclean

re: fclean $(NAME)

.PHONY: all clean fclean re
