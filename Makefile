all: main

CC = gcc
CFLAGS = -std=c11 -Werror -Wall -Wextra

.PHONY: all run clean

main: main.c
	$(CC) $(CFLAGS) $^ -o "$@"

run: main
	./$^

clean: main
	rm $^


