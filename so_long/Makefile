# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpedro-s < jpedro-s@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 00:46:33 by jpedro-s          #+#    #+#              #
#    Updated: 2022/04/08 00:20:14 by jpedro-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIBFT_DIR	= ./libft

SRCS		=	mapa.c \

NAME		=	so_long
CC			=	gcc
MLXFLAGS	=	-lX11 -lXext -lmlx -Ilmlx
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

OBJS		= $(SRCS:.c=.o)

mapa:
	$(CC) $(SRCS) $(CFLAGS) $(MLXFLAGS) -o $(NAME)

run: all
	./so_long
