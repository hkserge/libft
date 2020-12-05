# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: khelegbe <khelegbe@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 13:23:27 by khelegbe          #+#    #+#              #
#    Updated: 2020/12/05 18:47:10 by khelegbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= clang

FLAGS	= -Wall -Wextra -Werror

NAME	= libft.a

SRCS	= $(wildcard *.c)

HEADERS	= .

OBJECTS	= ${SRCS:.c=.o}

all:		$(NAME)

.c.o:
			${CC} ${FLAGS} -I ${HEADERS} -c $< -o ${<:.c=.o}

$(NAME) :	${OBJECTS}
			ar rc libft.a ${OBJECTS}

clean:
			rm -rf ${OBJECTS}

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:            all clean fclean re bonus
