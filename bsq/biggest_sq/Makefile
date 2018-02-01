CC =gcc
SRC_DIR =srcs/
INCLUDE=include/
CFLAGS =-I$(INCLUDE) -Wall -Wextra -Werror
OUTPUT =bsq
SRC := main.c $(wildcard $(SRC_DIR)/*.c)
OBJ := $(SRC:.c=.o) 

all: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $(OUTPUT) && make clean
	
clean:
	rm -f *.o $(SRC_DIR)*.o *~ core

fclean: clean
	rm -f $(OUTPUT)

run: fclean all
	./$(OUTPUT)

re: fclean all
