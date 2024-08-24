
CC = gcc
CFLAGS = -Wall -Werror -Wextra 
build: s21_grep.o
	$(CC) $(CFLAGS) -std=c11 -o s21_grep s21_grep.c

s21_grep.o:
	  $(CC) $(CFLAGS) -std=c11 -c s21_grep.c
rebuild:
	rm s21_grep
	$(CC) $(CFLAGS) -o s21_grep s21_grep.c
test:
	make
	sh test.sh

clean:
	rm -rf *.o
	rm s21_grep