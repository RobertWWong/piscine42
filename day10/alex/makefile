CC=gcc

.PHONY: all

all: $(OBJ)
	$(CC) -o "do-op" -Wall -Wextra -Werror main.c helper_functions.c

.PHONY: clean

clean:
	rm -f "do-op"
