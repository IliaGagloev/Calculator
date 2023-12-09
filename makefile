all : run
	rm main
run : comp
	./main
comp :
	gcc func.c Funcs16.c Funcs2.c Funcs8.c main.c -o main