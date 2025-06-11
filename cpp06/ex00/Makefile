NAME = convert

SOURCES =	main.cpp \
		ScalarConverter.cpp \

OBJECTS = $(SOURCES:%.cpp=%.o)

CC	=	c++ 
CFLAGS = -Wall -Werror -Wextra -std=c++11

all: $(NAME)

%.o:	%.cpp
	$(CC)	$(CFLAGS)	-c	$<	-o	$@

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

