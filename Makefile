#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/24 11:45:39 by aforcada          #+#    #+#              #
#    Updated: 2026/05/24 11:47:44 by aforcada         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = server client

LIBFT = ./libft

CC = gcc

CFLAGS = -Werror -Wall -Wextra -I$(LIBFT) -g

LFLAGS = -L$(LIBFT)

SOURCES = \
	server.c\
	client.c\

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)
	@make clean -C $(LIBFT)

$(NAME): $(OBJECTS) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(LFLAGS) $^ -o $@

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: clean all

.PHONY: all clean fclean re