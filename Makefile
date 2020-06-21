CC=g++
IPATH=-Iinc/
SRC=src/
OBJ=obj/
BIN=bin/
FLAGS=-std=c++11 -w

all: app
	@echo "Sucess"

app: main.o engine.o
	@$(CC) $(OBJ)* -o $(BIN)app $(FLAGS)
	
main.o:
	@$(CC) $(IPATH) -c $(SRC)main.cpp -o $(OBJ)main.o

run:
	@./bin/app

dev: app
	@./bin/app

clean: 
	@rm -rf $(OBJ)*.o $(BIN)*
