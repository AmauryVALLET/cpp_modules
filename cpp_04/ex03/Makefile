NAME	= Materia

CC		= c++
CFLAGS	= -Werror -Wextra -Wall -std=c++98

SRCS	= AMateria.cpp Character.cpp Cure.cpp Ice.cpp MateriaSource.cpp main.cpp
OBJS	= $(SRCS:.cpp=.o)
INC		= -I ./

all: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(INC)


clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean