# Variáveis de locais do build
INC=./include
SRC=./src
OBJ=./build/obj
LIB=./build/lib
BIN=./build/bin
DOCS=./build/docs
LOGS=./build/logs
LIBS=-lDicionario -lArvore -lPalavra -lTexto -lTimer

# Variáveis do compilador e flags
CC=g++
CFLAGS=-I$(INC) $(EF) -std=c++14

all: build docs

debug: $(SRC)/main.cpp dirs Dicionario.a Arvore.a Palavra.a Texto.a
	$(CC) $(SRC)/main.cpp $(CFLAGS) -g -DDEBUG -L$(LIB) $(LIBS) -o$(BIN)/corretor
	cp data/* $(BIN)/.
	cd $(BIN) && gdb corretor

build: $(SRC)/main.cpp dirs Dicionario.a Arvore.a Palavra.a Texto.a
	$(CC) $(SRC)/main.cpp $(CFLAGS) -L$(LIB) $(LIBS) -Ofast -o$(BIN)/corretor
	cp data/* $(BIN)/.

Dicionario: Dicionario.a Arvore.o Palavra.o
	$(CC) $(CFLAGS) -L$(LIB) $(LIBS) -o$(BIN)/dicionario

dirs:
	mkdir -p $(OBJ) $(LIB) $(BIN) $(DOCS) $(LOGS)

clean:
	rm -rf *~ ./build

docs: dirs
	doxygen doxygen.conf > $(LOGS)/doxygen.log
	cd $(DOCS)/latex
	$(MAKE) -C $(DOCS)/latex > $(LOGS)/pdftex.log
	cp "$(DOCS)/latex/refman.pdf" "$(BIN)/documentação.pdf"

Texto.a: $(SRC)/Texto.cpp $(INC)/Texto.hpp dirs Palavra.a Timer.a
	$(CC) $(CFLAGS) -c $(SRC)/Texto.cpp -o$(OBJ)/Texto.o
	ar -cr $(LIB)/libTexto.a $(OBJ)/Texto.o

Dicionario.a: $(SRC)/Dicionario.cpp $(INC)/Dicionario.hpp dirs Arvore.a
	$(CC) $(CFLAGS) -c $(SRC)/Dicionario.cpp -o$(OBJ)/Dicionario.o
	ar -cr $(LIB)/libDicionario.a $(OBJ)/Dicionario.o

Arvore.a: $(SRC)/Arvore.cpp $(INC)/Arvore.hpp dirs Palavra.a
	$(CC) $(CFLAGS) -c $(SRC)/Arvore.cpp -o$(OBJ)/Arvore.o
	ar -cr $(LIB)/libArvore.a $(OBJ)/Arvore.o

Timer.a: $(SRC)/Timer.cpp $(INC)/Timer.hpp dirs
	$(CC) $(CFLAGS) -c $(SRC)/Timer.cpp -o$(OBJ)/Timer.o
	ar -cr $(LIB)/libTimer.a $(OBJ)/Timer.o

Palavra.a: $(SRC)/Palavra.cpp $(INC)/Palavra.hpp dirs
	$(CC) $(CFLAGS) -c $(SRC)/Palavra.cpp -o$(OBJ)/Palavra.o
	ar -cr $(LIB)/libPalavra.a $(OBJ)/Palavra.o

clear:
	del dicionario *.o
