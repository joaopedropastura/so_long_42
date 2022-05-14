# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 00:46:33 by jpedro-s          #+#    #+#              #
#    Updated: 2022/05/15 01:00:04 by jpedro-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_DIR	= ./libft
LIBFT_A		= -L $(LIBFT_DIR) -lft

SRCS		=	errors.c\
				game_close.c\
				game_draw.c\
				game_init.c\
				game_play.c\
				map_read.c \
				map_validate.c\
				so_long.c\
# SRCS_BONUS	=

NAME		=	so_long
NAME_BONUS	=	so_long_bonus
SRC_DIR		=	./src
BONUS_DIR	=	./src_bonus
CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror -g3
MLXFLAGS	=	-lmlx -Ilmlx -lXext -lX11
RM			=	rm -rf
VALGRIND	=	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -q --tool=memcheck
MAP			=	maps/map.ber
OBJ_DIR		=	obj

OBJS		=	$(SOURCES:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS: .c=.o)
SRCS_A		=	$(SRC_DIR)/so_long.a
SOURCES		=	$(addprefix $(SRC_DIR)/,$(SRCS))

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:%.c=%.o)

# bonus: $(NAME_BONUS)

$(LIBFT_A):

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(MLXFLAGS) -o $(NAME)

run: all
	./so_long

valgrind: all
	$(VALGRIND) ./so_long $(MAP)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus
