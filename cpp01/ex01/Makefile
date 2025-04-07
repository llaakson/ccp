NAME = Zombie

SOURCES =	main.cpp \
			Zombie.cpp \
			zombieHord.cpp \

OBJECTS = $(SOURCES:%.cpp=%.o)

CC	=	c++ 
CFLAGS =

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
