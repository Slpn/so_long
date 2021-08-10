# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snarain <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 19:06:53 by snarain           #+#    #+#              #
#    Updated: 2021/08/10 22:19:37 by snarain          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

FLAGS	= -Wall -Wextra -Werror

DEL = /bin/rm -f

SRCS = \

SRCS_O	= ${SRCS:.c=.o}

INCLUDES = so_long.h \
		   \

all: $(NAME)

LIBC	= ar -rcs

bonus: ${NAME}

%.o: %.c
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME): ${SRCS_O} ${INCLUDES}
		${LIBC} $(NAME) $(SRCS_O)

fclean: clean
		$(DEL) $(NAME)

clean:
		$(DEL) $(SRCS_O)

re: fclean all
