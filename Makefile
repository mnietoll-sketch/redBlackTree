compile: rbTree.h rbTree.c main.c
	gcc -c rbTree.c main.c

test: compile
	gcc rbTree.o main.o -o test

run: test
	./test
