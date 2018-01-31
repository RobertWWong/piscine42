CC =gcc
CFLAGS =-Iinclude/ -Wall -Wextra -Werror

OUTPUT =bsq
INCLUDE=includes/
SRC_DIR=srcs/

SRC := main.c $(wildcard srcs/*.c)
OBJ := $(SRC:.c=.o) 

all: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(OUTPUT) && make clean
	
clean:
	rm -f *.o *~ core

fclean: clean
	rm -f $(OUTPUT)

run: all
	./$(OUTPUT)

re: fclean all
