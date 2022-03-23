# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abziouzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 15:40:28 by abziouzi          #+#    #+#              #
#    Updated: 2022/03/23 22:55:13 by abziouzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all bonus clean fclean re

all: server client bonus

server: server.c minitalk.h
	$(CC) $(CFLAGS) server.c -o server

client: client.c minitalk.h
	$(CC) $(CFLAGS) client.c -o client

bonus: client_bonus.c server_bonus.c minitalk_bonus.h
	$(CC) $(CFLAGS) server_bonus.c  -o server_bonus
	$(CC) $(CFLAGS) client_bonus.c  -o client_bonus

clean:
	@rm -rf server client

fclean: clean
	@rm -rf server client server_bonus client_bonus

re: fclean all

