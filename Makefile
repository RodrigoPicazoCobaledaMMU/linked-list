CC = gcc
TARGET = linkedList
FLAGS = -O3 -Wall -Wextra
SRC = linkedList.c

make: 
	$(CC) $(FLAGS) -o $(TARGET) $(SRC)

clean:
	rm $(TARGET)
