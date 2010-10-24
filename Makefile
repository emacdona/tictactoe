CFLAGS = -g -O0

ttt: main.o board.o
	$(CC) $(CFLAGS) -o $@ main.o board.o 

main.o: main.c board.h
	$(CC) $(CFLAGS) -c -o $@ main.c

board.o: board.c board.h
	$(CC) $(CFLAGS) -c -o $@ board.c 

clean:
	rm -rf ttt *.o
