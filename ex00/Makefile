# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aammirat <aammirat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 14:59:58 by aammirat          #+#    #+#              #
#    Updated: 2025/01/15 10:36:26 by aammirat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= btc

SRCS	= main.cpp \
			BitcoinExchange.cpp

HEADERS = BitcoinExchange.hpp

CC 		= c++

CFLAGS	= -Wextra -Wall -Werror -std=c++98

OBJS 	= $(SRCS:.cpp=.o)

%.o : %.cpp ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
	${CC} ${OBJS} -o ${NAME}

all: ${NAME}

clean: 
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: clean re fclean all