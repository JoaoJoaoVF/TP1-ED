#---------------------------------------------------------------------
# Arquivo	: Makefile
# Conteúdo	: compilar o programa Poker
# Autor		: Joao Vitor Ferreira (ferreirajoao@dcc.ufmg.br)
# Histórico	: 2022-06-07 - arquivo criado
#---------------------------------------------------------------------
# Opções	: make all - compila tudo
#			: make clean - remove objetos e executável
#---------------------------------------------------------------------

CC = g++
LIBS = -lm 
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/jogador.o $(OBJ)/pote.o $(OBJ)/rodada.o $(OBJ)/partida.o $(OBJ)/baralho.o $(OBJ)/main.o $(OBJ)/memlog.o
HDRS = $(INC)/memlog.h $(INC)/msgassert.h $(INC)/baralho.hpp $(INC)/jogador.hpp $(INC)/pote.hpp $(INC)/rodada.hpp $(INC)/partida.hpp $(INC)/memlog.h $(INC)/msgassert.h
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/tp1

all: use

use: $(EXE)
	$(EXE) -pg -o tp1 

$(BIN)/tp1: $(OBJS)
	$(CC) -g -o $(BIN)/tp1 $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/jogador.o: $(HDRS) $(SRC)/jogador.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/jogador.o $(SRC)/jogador.cpp 

$(OBJ)/pote.o: $(HDRS) $(SRC)/pote.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pote.o $(SRC)/pote.cpp 

$(OBJ)/rodada.o: $(HDRS) $(SRC)/rodada.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/rodada.o $(SRC)/rodada.cpp 

$(OBJ)/partida.o: $(HDRS) $(SRC)/partida.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/partida.o $(SRC)/partida.cpp 

$(OBJ)/baralho.o: $(HDRS) $(SRC)/baralho.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/baralho.o $(SRC)/baralho.cpp 

$(OBJ)/memlog.o: $(HDRS) $(SRC)/memlog.c
	$(CC) $(CFLAGS) -o $(OBJ)/memlog.o $(SRC)/memlog.c

clean:
	rm -f $(EXE) $(OBJS)  
