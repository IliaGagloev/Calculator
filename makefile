.PHONY: all run mem clean

cc = gcc
isp = main
all: main

main: func.o Funcs16.o Funcs2.o Funcs8.o check_base.o main.o
	$(cc) func.o Funcs16.o Funcs2.o Funcs8.o check_base.o main.o -o main

func.o: func.c
	$(cc) -c func.c -o func.o

Funcs16.o: Funcs16.c
	$(cc) -c Funcs16.c -o Funcs16.o

Funcs8.o: Funcs8.c
	$(cc) -c Funcs8.c -o Funcs8.o

Funcs2.o: Funcs2.c
	$(cc) -c Funcs2.c -o Funcs2.o

check_base.o: check_base.c
	$(cc) -c check_base.c -o check_base.o

run : main 
	./main
clean:
	rm main
	rm *.o

mem: main
	valgrind --track-origins=yes ./main
