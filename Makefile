# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: julrodri <julrodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/25 20:54:10 by julrodri          #+#    #+#              #
#    Updated: 2022/04/04 09:54:26 by julrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC = printf.c libft.c converters.c

OBJ = ${SRC:%.c=%.o} 

all: ${NAME}

${NAME}: ${OBJ} 
	ar -crs ${NAME} ${OBJ}

%.o: %.c
	cc ${FLAGS} -c $<

clean:
	rm -f ${OBJ}

fclean: clean 
	rm -f ${NAME}

re: clean all

.PHONY: all clean fclean re