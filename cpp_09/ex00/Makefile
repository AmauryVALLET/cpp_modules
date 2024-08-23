# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avallet <avallet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 12:12:23 by avallet           #+#    #+#              #
#    Updated: 2024/02/28 12:13:42 by avallet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = btc

CC = c++ -std=c++98
CFLAGS = -Wall -Wextra -Werror

FILES = main.cpp BitcoinExchange.cpp
OBJ = $(FILES:.cpp=.o)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re