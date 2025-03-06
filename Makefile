CC = g++
CFLAGS = -std=c++11 -Wall -I/usr/include/freetype2
LIBS = -L/usr/local/lib/ -lbbop -lglfw3 -lGLEW -lGL -lfreetype -lLDtkLoader

SRC_DIR = src
SRCS = main.cpp $(SRC_DIR)/Canne.cpp
OBJS = main.o $(SRC_DIR)/Canne.o

all: final

final: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

main.o: main.cpp
	$(CC) $(CFLAGS) -c -o $@ main.cpp

$(SRC_DIR)/Canne.o: $(SRC_DIR)/Canne.cpp
	$(CC) $(CFLAGS) -c -o $@ $(SRC_DIR)/Canne.cpp

clean:
	rm -f final main.o $(SRC_DIR)/Canne.o
