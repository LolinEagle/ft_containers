# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: frrusso <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/30 11:39:41 by frrusso           #+#    #+#              #
#    Updated: 2023/01/30 11:39:43 by frrusso          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_containers
SRC			=	ft_containers.cpp
CPP			=	c++
CPPFLAGS	=	-Wall -Wextra -Werror -std=c++98 -MMD
RM			=	rm -rf
INC			=	-I ./
SRC_PATH	=	./
OBJ_PATH	=	./obj/
OBJ_DIRS	=	${OBJ_PATH}
OBJ			=	${addprefix ${OBJ_PATH},${SRC:.cpp=.o}}
DEPS		=	${addprefix ${OBJ_PATH},${SRC:.cpp=.d}}

all:${NAME}

clean:
	${RM} ${OBJ_PATH}

fclean:clean
	${RM} ${NAME}

re:fclean
	make all

run:${NAME}
	clear
	./${NAME}

${OBJ_PATH}%.o:${SRC_PATH}%.cpp
	${CPP} ${CPPFLAGS} ${INC} -c $< -o $@

${OBJ_DIRS}:
	mkdir ${OBJ_DIRS}

${NAME}:${OBJ_DIRS} ${OBJ}
	${CPP} ${OBJ} -o $@

.PHONY:all clean fclean re run

-include ${DEPS}