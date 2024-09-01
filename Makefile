CC = gcc
CFLAGS = -Wall
OBJ = main.o game.o

all: game

game: $(OBJ)
	$(CC) -o game $(OBJ)

main.o: main.c game.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

clean:
	rm -f *.o game
