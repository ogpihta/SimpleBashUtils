FLAGS = -Wall -Werror -Wextra -std=c11

SRC = s21_cat.c
OBJ = s21_cat a.out a b res

all: clean build

build: s21_cat

test: s21_cat
	python3 test_cat.py

s21_cat: s21_cat.c
	gcc $(FLAGS) $(SRC) -o s21_cat

clean:
	rm -rf $(OBJ) my_cat result system