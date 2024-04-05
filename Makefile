# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 11:22:27 by fdiaz-gu          #+#    #+#              #
#    Updated: 2024/04/05 16:23:55 by fdiaz-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

SRC_DIR = ./src

SRCS = main.c aux_functions.c check_args.c routine.c init.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))

RM = rm -rf

all: $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
re: fclean
	@make all

.PHONY: all re clean fclean

