# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vimucchi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/12 16:38:13 by vimucchi          #+#    #+#              #
#    Updated: 2018/11/14 16:12:12 by vimucchi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl
SRC_PATH = ./
OBJ_PATH = ./
INC = -Iincludes
LDFLAGS = -L./libft
LDLIBS = -lft
CFLAGS = -Wall -Wextra -Werror -g
CC = CLANG
SRC = main.c \
		get_next_line.c \
		get_next_line_fd.c

all: $(NAME)

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@echo "\033[32m>>\033[0m \033[33mStarting library & $(NAME)\033[32m compilation\033[0m \033[0m"
	@make -C libft
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@.out
	@echo "\033[32m>> $(NAME) correctly created ... OK\033[0m"

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@make -C libft clean
	@echo "\033[32mObjects \033[31mremoved\033[0m"

fclean: clean
	@rm -f $(NAME).out
	@make -C libft fclean
	@echo "\033[32m$(NAME) \033[31mremoved\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
