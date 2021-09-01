# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snarain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 19:06:53 by snarain           #+#    #+#              #
#    Updated: 2021/09/01 19:26:45 by snarain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =    main.c \

OBJS         = ${SRCS:.c=.o}

UNAME        := $(shell uname)

PATH_MLX    = mlx
CC             = gcc
RM            = rm -f
NAME        = so_long

all:         ${NAME}

.c.o:
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make -C $(PATH_MLX) clean
	${RM} ${OBJS}

fclean:	clean
	make -C $(PATH_MLX) clean
	${RM} ${NAME}

re:         fclean all

.PHONY:        bonus all clean fclean re
