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
CXX=g++
OPTFLAGS=-Ofast
CXXFLAGS=-I$(INC) $(EF) $(OPTFLAGS) -std=c++14 -Wall

all: clean build docs

dirs:
	mkdir -p $(OBJ) $(LIB) $(BIN) $(DOCS) $(DOCS)-tmp $(LOGS)

clean:
	rm -rf *~ ./build

docs: dirs
	doxygen doxygen.conf > $(LOGS)/doxygen.log
	$(MAKE) -C "$(DOCS)-tmp/latex" > $(LOGS)/doxygen.latex.log 2>&1
	cp "$(DOCS)-tmp/latex/refman.pdf" "$(DOCS)/DOCUMENTAÇÃO.pdf"
	rm -rf "$(DOCS)/html" && mkdir -p "$(DOCS)/html" && mv -f "$(DOCS)-tmp/html" "$(DOCS)/."

build: dirs main.o Dicionario.o Arvore.o Palavra.o Texto.o Corretor.o
	$(CXX) $(OBJ)/main.o $(CXXLAGS) $(LIBS) -o$(BIN)/corretor
	cp data/* $(BIN)/.

debug:
	$(MAKE) build "EF=-ggdb -DDEBUG" OPTFLAGS=-O0
	cd $(BIN) && gdb corretor

run: build
	cd $(BIN) && ./corretor

main.o: $(SRC)/main.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/main.cpp -o$(OBJ)/main.o

Texto.o: $(SRC)/Texto.cpp $(INC)/Texto.hpp Palavra.o
	$(CXX) $(CXXFLAGS) -c $(SRC)/Texto.cpp -o$(OBJ)/Texto.o

Dicionario.o: $(SRC)/Dicionario.cpp $(INC)/Dicionario.hpp Arvore.o
	$(CXX) $(CXXFLAGS) -c $(SRC)/Dicionario.cpp -o$(OBJ)/Dicionario.o

Arvore.o: $(SRC)/Arvore.cpp $(INC)/Arvore.hpp Palavra.o
	$(CXX) $(CXXFLAGS) -c $(SRC)/Arvore.cpp -o$(OBJ)/Arvore.o

Corretor.o: $(SRC)/Corretor.cpp $(INC)/Corretor.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/Corretor.cpp -o$(OBJ)/Corretor.o

Palavra.o: $(SRC)/Palavra.cpp $(INC)/Palavra.hpp
	$(CXX) $(CXXFLAGS) -c $(SRC)/Palavra.cpp -o$(OBJ)/Palavra.o
