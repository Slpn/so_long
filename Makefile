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

SRCS	 	=	src/GNL/get_next_line.c \
				src/GNL/get_next_line_utils.c \
				src/check_file.c \
				src/draw.c \
				src/ft_free.c \
				src/get_xpm.c \
				src/init.c \
				src/main.c \
				src/map.c \
				src/move.c

OBJS 		= 	${SRCS:.c=.o}


PATH_MLX	= 	mlx
PATH_LIB	= 	src/libft
CC 			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror
LIB 		=	src/libft/libft.a mlx/libmlx_linux.a
RM			= 	rm -f
NAME		= 	so_long
FLAGS		= 	-ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -g

all: 			${NAME}

.c.o:
				${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 		$(OBJS)
				make -C $(PATH_MLX)
				make -C $(PATH_LIB)
				${CC} $(CFLAGS) $(OBJS) $(FLAGS) $(LIB) -o $(NAME)

clean:
				make -C $(PATH_MLX) clean
				make -C $(PATH_LIB) clean
				${RM} ${OBJS}

fclean: 		clean
				make -C $(PATH_MLX) clean
				make -C $(PATH_LIB) clean
				${RM} ${NAME}

re: 			fclean all

.SILENT:		$(NAME)

.PHONY:			bonus all clean fclean re
