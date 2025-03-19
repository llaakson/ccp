NAME = account

SOURCES =	Account.cpp tests.cpp \

CC	=	c++

all: $(NAME)

$(NAME): $(SOURCES)
	$(CC) $(SOURCES) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re
