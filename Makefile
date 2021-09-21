# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snarain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 19:06:53 by snarain           #+#    #+#              #
#    Updated: 2021/09/19 03:33:43 by snarain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	src/GNL/get_next_line.c \
		src/GNL/get_next_line_utils.c \
		src/check_file.c \
		src/draw.c \
		src/ft_free.c \
		src/get_xpm.c \
		src/init.c \
		src/main.c \
		src/map.c \
		src/move.c \
		src/libft/*.c

OBJS 		= ${SRCS:.c=.o}


PATH_MLX	= mlx
PATH_LIB	= src/libft
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
NAME		= so_long
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS} ${OBJS_M}

fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		bonus all clean fclean re
