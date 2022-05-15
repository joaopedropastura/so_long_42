# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpedro-s <jpedro-s@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/14 06:03:48 by jpedro-s          #+#    #+#              #
#    Updated: 2022/05/15 02:06:54 by jpedro-s         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_atoi.c \
		ft_substr.c \
		ft_strlcpy.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_memset.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strchr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putnbr_fd.c \
		ft_itoa.c \
		ft_putendl_fd.c \
		ft_split.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strtrim.c \
		ft_uitoa.c \
		ft_base_converter.c \
		get_next_line.c \
		ft_substr_gnl.c \
		ft_printf.c \
		ft_types.c \

NAME = libft.a

CC = clang

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

RM = rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
