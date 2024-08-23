NAME	= Reference

CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98


SRC			=	main.cpp
		
SRCS		= $(addprefix $(SRC))

OBJ_PATH	= ./objects/
OBJ			= $(SRC:.cpp=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean