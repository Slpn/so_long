# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snarain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 19:06:53 by snarain           #+#    #+#              #
#    Updated: 2021/08/11 02:41:52 by snarain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

FLAGS	= -Wall -Wextra -Werror -Imlx

DEL = /bin/rm -f

SRCS = main.c \

SRCS_O	= ${SRCS:.c=.o}

MLX = minilibx

all: $(NAME)

bonus: ${NAME}

%.o: %.c
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${SRCS_O} ${INCLUDES}
		make -C ${MLX}
		${CC} ${FLAGS} -o $(NAME) $(SRCS_O)

fclean: clean
		$(DEL) $(NAME)

clean:
		$(DEL) $(SRCS_O)

re: fclean all
