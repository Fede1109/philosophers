# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fdiaz-gu <fdiaz-gu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 11:22:27 by fdiaz-gu          #+#    #+#              #
#    Updated: 2024/03/20 10:58:54 by fdiaz-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src

SRCS = main.c aux_functions.c check_args.c

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

