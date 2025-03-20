NAME = account

SOURCES =	Account.cpp tests.cpp \

CC	=	c++ -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(SOURCES) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
