cc = gcc
isp = main

all : run
	rm isp
run : comp
	./isp
comp :
	cc func.c Funcs16.c Funcs2.c Funcs8.c check_base.c main.c -o isp
mem: comp
	valgrind --track-origins=yes ./isp 
