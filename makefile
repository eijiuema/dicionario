# Variáveis de locais do build
INC=./include
SRC=./src
OBJ=./build/obj
LIB=./build/lib
BIN=./build/bin
DOCS=./build/docs
LOGS=./build/logs
LIBS=$(OBJ)/Dicionario.o $(OBJ)/Arvore.o $(OBJ)/Palavra.o $(OBJ)/Texto.o $(OBJ)/Corretor.o
# Variáveis do compilador e flags
CC=g++
OPTFLAGS=-Ofast
CXXLAGS=-I$(INC) $(EF) $(OPTFLAGS) -std=c++14

all: build docs

debug:
	$(MAKE) build "EF=-ggdb -DDEBUG" OPTFLAGS=-O0
	cd $(BIN) && gdb corretor

build: main.o dirs Dicionario.a Arvore.a Palavra.a Texto.a Corretor.a
	$(CC) $(OBJ)/main.o $(CXXLAGS) $(LIBS) -o$(BIN)/corretor
	cp data/* $(BIN)/.

run: build
	cd $(BIN) && ./corretor

Dicionario: Dicionario.a Arvore.o Palavra.o
	$(CC) $(CXXLAGS) -L$(LIB) $(LIBS) -o$(BIN)/dicionario

dirs:
	mkdir -p $(OBJ) $(LIB) $(BIN) $(DOCS) $(LOGS)

clean:
	rm -rf *~ ./build

docs: dirs
	doxygen doxygen.conf > $(LOGS)/doxygen.log
	cd $(DOCS)/latex
	$(MAKE) -C $(DOCS)/latex
	cp "$(DOCS)/latex/refman.pdf" "$(BIN)/documentação.pdf"

main.o: $(SRC)/main.cpp
	$(CC) $(CFLAGS) -c $(SRC)/main.cpp -o$(OBJ)/main.o

Texto.a: $(SRC)/Texto.cpp $(INC)/Texto.hpp dirs Palavra.a
	$(CC) $(CFLAGS) -c $(SRC)/Texto.cpp -o$(OBJ)/Texto.o
	ar -cr $(LIB)/libTexto.a $(OBJ)/Texto.o

Dicionario.a: $(SRC)/Dicionario.cpp $(INC)/Dicionario.hpp dirs Arvore.a
	$(CC) $(CFLAGS) -c $(SRC)/Dicionario.cpp -o$(OBJ)/Dicionario.o
	ar -cr $(LIB)/libDicionario.a $(OBJ)/Dicionario.o

Arvore.a: $(SRC)/Arvore.cpp $(INC)/Arvore.hpp dirs Palavra.a
	$(CC) $(CFLAGS) -c $(SRC)/Arvore.cpp -o$(OBJ)/Arvore.o
	ar -cr $(LIB)/libArvore.a $(OBJ)/Arvore.o

Corretor.a: $(SRC)/Corretor.cpp $(INC)/Corretor.hpp dirs
	$(CC) $(CFLAGS) -c $(SRC)/Corretor.cpp -o$(OBJ)/Corretor.o
	ar -cr $(LIB)/libCorretor.a $(OBJ)/Corretor.o

Palavra.a: $(SRC)/Palavra.cpp $(INC)/Palavra.hpp dirs
	$(CC) $(CFLAGS) -c $(SRC)/Palavra.cpp -o$(OBJ)/Palavra.o
	ar -cr $(LIB)/libPalavra.a $(OBJ)/Palavra.o

clear:
	del dicionario *.o
