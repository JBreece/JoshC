TARGET = runsudoku

CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRCS = main.c generatePuzzle.c display.c
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

main.o: main.c generatePuzzle.h display.h
generatePuzzle.o: generatePuzzle.c generatePuzzle.h
display.o: display.c display.h

clean:
	rm -f $(TARGET) $(OBJS)
