# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snarain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 19:06:53 by snarain           #+#    #+#              #
#    Updated: 2021/08/12 22:26:44 by snarain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =    main.c \

OBJS         = ${SRCS:.c=.o}

UNAME        := $(shell uname)

PATH_MLX    = mlx
CC             = gccs
CFLAGS        = -Wall -Wextra -Werror
RM            = rm -f
NAME        = so_long
FLAGS        = -lmlx -lX11 -lXext OpenGL AppKit

all:         ${NAME}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	make -C $(PATH_MLX)
	${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
	make -C $(PATH_MLX) clean
	${RM} ${OBJS}

fclean:	clean
	make -C $(PATH_MLX) clean
	${RM} ${NAME}

re:         fclean all

.PHONY:        bonus all clean fclean re
