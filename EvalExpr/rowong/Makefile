CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC=$(wildcard *.c)
OUTPUT = eval_expr

.PHONEY: all

all: $(SRC)
	$(CC) $(CFLAGS) -o $(OUTPUT) $^  

.PHONEY: clean
	
clean:
	rm -f *.o *~ core

fclean: clean
	rm -f $(OUTPUT)

re: clean all
