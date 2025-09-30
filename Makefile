all: main

CC = gcc
CFLAGS = -Werror -Wall -Wextra -pedantic -lm

.PHONY: all run clean

main: main.c
	$(CC) $(CFLAGS) $^ -o "$@"

run: main
	./$^

clean: main
	rm $^


