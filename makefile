CC = gcc
OBJS = main.o # list of object files


all: programa limpa

programa: $(OBJS)
	$(CC) $(OBJS) -L. -lcunit -o gpalestra

main.o: main.c
	$(CC) -c main.c

limpa:
	rm *.o

tar:
	find ./ -name '*.c' -o -name '*.h' -o -name '*.a' -o -name '*.dat' -o -name 'LEIAME' -o -name 'makefile' | tar -cf gpalestra.tar -T -
