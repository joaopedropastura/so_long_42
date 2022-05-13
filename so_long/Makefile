# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 00:46:33 by jpedro-s          #+#    #+#              #
#    Updated: 2022/05/13 00:13:58 by jpedro-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

SRCS		=	read_map.c \
				so_long.c\
				validate_map.c\
				errors.c\
				game_draw.c\
				game_init.c\
				game_play.c\
				game_close.c\

NAME		=	so_long
CC			=	clang -g3
MLXFLAGS	=	-lmlx -Ilmlx -lXext -lX11
CFLAGS		=	-Wall -Wextra -Werror -fPIE
RM			=	rm -rf

OBJS		= $(SRCS:.c=.o)
HEADER		= ./so_long.h

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
all: $(LIBFT)
	$(CC) $(CFLAGS) $(SRCS) $(LIBFT) $(MLXFLAGS) -o $(NAME)

run: all
	./so_long
