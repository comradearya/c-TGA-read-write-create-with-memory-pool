CC=g++
CFLAGS=-I. -w


lab02-4: main.o add.o pool.o 
	$(CC) -o lab02-4.exe main.cpp add.cpp pool.cpp $(CFLAGS)