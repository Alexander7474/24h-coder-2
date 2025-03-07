CC = g++
CFLAGS = -std=c++11 -Wall -I/usr/include/freetype2
LIBS = -L/usr/local/lib/ -lbbop -lglfw3 -lGLEW -lGL -lfreetype -lLDtkLoader

SRC_DIR = src
# Assure-toi que les noms de fichiers correspondent exactement (respect de la casse)
SRCS = main.cpp $(SRC_DIR)/Canne.cpp $(SRC_DIR)/banc.cpp $(SRC_DIR)/fish.cpp $(SRC_DIR)/Character.cpp
OBJS = main.o $(SRC_DIR)/Canne.o $(SRC_DIR)/banc.o $(SRC_DIR)/fish.o $(SRC_DIR)/Character.o

all: final

final: $(OBJS)
	$(CC) $(CFLAGS) -o final $(OBJS) $(LIBS)

# Règle générique pour compiler les fichiers .cpp en .o
%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f final main.o $(SRC_DIR)/*.o
