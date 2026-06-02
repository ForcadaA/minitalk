# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aforcada <aforcada@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/24 11:45:39 by aforcada          #+#    #+#              #
#    Updated: 2026/06/02 12:14:28 by aforcada         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Names
SERVER = server
CLIENT = client

# Repo
LIBFT = ./libft

# Compile Options
CC = gcc
CFLAGS = -Werror -Wall -Wextra -I$(LIBFT) -g
LFLAGS = -L$(LIBFT)

# Sources
SERVER_SRC = server.c
CLIENT_SRC = client.c
SOURCES = \
	ft_print_pid.c\
	error_handle.c\

# Objects
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
OBJECTS = $(SOURCES:.c=.o)

# Rules
all: $(SERVER) $(CLIENT)

$(LIBFT)/libft.a:
	@make -C $(LIBFT)
	@make clean -C $(LIBFT)

$(SERVER): $(SERVER_OBJ) $(OBJECTS) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(LFLAGS) $^  -o $@

$(CLIENT): $(CLIENT_OBJ) $(OBJECTS) $(LIBFT)/libft.a
	$(CC) $(CFLAGS) $(LFLAGS) $^  -o $@

clean:
	@rm -f $(OBJECTS)
	@rm	-f $(SERVER_OBJ)
	@rm -f $(CLIENT_OBJ)

fclean: clean
	@rm -f $(SERVER)
	@rm -f $(CLIENT)
	@make fclean -C $(LIBFT)

re: clean all

.PHONY: all clean fclean re