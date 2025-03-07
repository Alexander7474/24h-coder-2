CC = g++
CFLAGS = -std=c++11 -Wall -I/usr/include/freetype2 
LIBS = -L/usr/local/lib/ -lbbop -lglfw3 -lGLEW -lGL -lfreetype  -lLDtkLoader

SRCS = main.cpp src/banc.cpp src/fish.cpp src/Game.cpp src/Character.cpp src/Canne.cpp src/Menu.cpp src/LoadingBar.cpp
 
OBJS = $(SRCSM:.cpp=.o) $(SRCS:.cpp=.o)

all: final

final: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f final $(OBJS)
