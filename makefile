all: bibi.exe pro.exe
	echo "Compilation Complited"

bibi.exe: main.o intarray.o tools.o stats.o
	gcc stats.o main.o intarray.o tools.o -o bibi.exe

pro.exe: test.o tools.o intarray.o 
	gcc test.o intarray.o tools.o -o pro.exe

intarray.o: intarray.c tools.h intarray.h
	gcc -c intarray.c

tools.o: tools.c tools.h
	gcc -c tools.c

test.o: test.c intarray.h tools.h
	gcc -c test.c

main.o: main.c intarray.h tools.h stats.h
	gcc -c main.c

stats.o: stats.c intarray.h tools.h stats.h
	gcc -c stats.c