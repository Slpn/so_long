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


SRCS_BONUS	 =	src/GNL/get_next_line.c \
				src/GNL/get_next_line_utils.c \
				src/check_file.c \
				src/draw_bonus.c \
				src/ft_free.c \
				src/get_xpm.c \
				src/init.c \
				src/main_bonus.c \
				src/map.c \
				src/move.c

OBJS 		= 	${SRCS:.c=.o}
OBJS_BONUS	=	${SRCS_BONUS:.c=.o}

PATH_MLX	= 	mlx
PATH_LIB	= 	src/libft
CC 			= 	gcc
CFLAGS		= 	-Wall -Wextra -Werror
LIB 		=	src/libft/libft.a mlx/libmlx_linux.a
RM			= 	rm -f
NAME		= 	so_long
NAME_BONUS	= 	so_long_bonus
FLAGS		= 	-ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11 -g

all: 			${NAME}

bonus:			${NAME_BONUS}

.c.o:
				${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 		$(OBJS)
				make -C $(PATH_MLX)
				make -C $(PATH_LIB)
				${CC} $(CFLAGS) $(OBJS) $(FLAGS) $(LIB) -o $(NAME)

$(NAME_BONUS): 	$(OBJS_BONUS)
				make -C $(PATH_MLX)
				make -C $(PATH_LIB)
				${CC} $(CFLAGS) $(OBJS_BONUS) $(FLAGS) $(LIB) -o $(NAME_BONUS)

clean:
				make -C $(PATH_MLX) clean
				make -C $(PATH_LIB) clean
				${RM} ${OBJS} ${OBJS_BONUS}

fclean: 		clean
				make -C $(PATH_MLX) clean
				make -C $(PATH_LIB) clean
				${RM} ${NAME} ${NAME_BONUS}

re: 			fclean all

.SILENT:		$(NAME)

.PHONY:			bonus all clean fclean re
