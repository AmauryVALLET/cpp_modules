# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avallet <avallet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/28 16:31:09 by avallet           #+#    #+#              #
#    Updated: 2024/02/28 18:20:18 by avallet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME		:= RPN

CC			:= c++
FLAGS		:= -Wall -Wextra -Werror -MMD -std=c++98 -g3

SRC			:= 	main.cpp \
				RPN.cpp \


OBJ_DIR 	:= ./objs/
C_OBJ_DIR	:= @mkdir -p $(OBJ_DIR)
OBJ			:=$(SRC:.cpp=.o)
OBJ			:=$(addprefix $(OBJ_DIR), $(OBJ))

DEPS		:=$(OBJ:.o=.d)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) 

$(OBJ_DIR)%.o: %.cpp
	$(C_OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

debug: FLAGS += -D DEBUG
debug: re

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re

-include $(DEPS)