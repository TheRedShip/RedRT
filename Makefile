NAME = opengl

CC = gcc

CFLAGS = -pedantic -lglu32 -lfreeglut -lopengl32 -Wl,--subsystem,windows

SRC = $(wildcard srcs/*.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re