#Pastas
INC_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
DATA_DIR = ./data

#Variaveis
CC = g++
CFLAGS = -Wall -Wextra -std=c++11

output: $(OBJ_DIR)/main.o $(OBJ_DIR)/search.o $(OBJ_DIR)/util.o
	mkdir -p bin
	mkdir -p data
	$(CC) $(CFLAGS) $(OBJ_DIR)/main.o $(OBJ_DIR)/search.o $(OBJ_DIR)/util.o -o $(BIN_DIR)/analiseEmpirica

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/main.cpp -I $(INC_DIR) -o $(OBJ_DIR)/main.o $(CFLAGS)

$(OBJ_DIR)/search.o: $(SRC_DIR)/search.cpp $(INC_DIR)/search.h
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/search.cpp -I $(INC_DIR) -o $(OBJ_DIR)/search.o $(CFLAGS)

$(OBJ_DIR)/util.o: $(SRC_DIR)/util.cpp $(INC_DIR)/util.h
	mkdir -p obj
	$(CC) -c $(SRC_DIR)/util.cpp -I $(INC_DIR) -o $(OBJ_DIR)/util.o $(CFLAGS)

clear:
	rm -r $(OBJ_DIR) $(BIN_DIR)

cleardata:
	rm $(DATA_DIR)/*