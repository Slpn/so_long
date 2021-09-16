# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snarain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 19:06:53 by snarain           #+#    #+#              #
#    Updated: 2021/09/16 20:06:06 by snarain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = so_long

SRCS =	 ./src/GNL/get_next_line.c \
		 ./src/GNL/get_next_line_utils.c \
		 ./src/check_file.c \
		 ./src/draw.c \
		 ./src/ft_free.c \
		 ./src/get_xpm.c \
		 ./src/init.c \
		 ./src/init_texture.c \
		 ./src/main.c \
		 ./src/map.c \
		 ./src/move.c \


OBJS         = ${SRCS:.c=.o}

UNAME        := $(shell uname)

PATH_MLX	= ./mlx

CC			= gcc

RM			= rm -f

FLAGS		=  -Lmlx_linux -lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o

all:         ${NAME}

.c.o:
	$(CC) -Wall -Wextra -Werror -c $< -o

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(NAME) $(OBJS)

clean:
	make -C $(PATH_MLX) clean
	${RM} ${OBJS}

fclean:	clean
	make -C $(PATH_MLX) clean
	${RM} ${NAME}

re:         fclean all

.PHONY:        bonus all clean fclean re
