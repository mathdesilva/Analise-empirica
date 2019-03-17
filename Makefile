#Pastas
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin

#Variaveis
CC = g++
CFLAGS = -Wall -std=c++11

output: $(OBJ_DIR)/main.o $(OBJ_DIR)/search.o
	mkdir -p bin
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/search.o -o $(BIN_DIR)/analiseEmpirica

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/main.cpp -I $(INC_DIR) -o $(OBJ_DIR)/main.o $(CFLAGS)

$(OBJ_DIR)/search.o: $(SRC_DIR)/search.cpp $(INC_DIR)/search.h
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/search.cpp -I $(INC_DIR) -o $(OBJ_DIR)/search.o $(CFLAGS)

clear:
	rm -r $(OBJ_DIR) $(BIN_DIR)