dicionario: dicionario.o arvore.o palavra.o
	g++ -o dicionario dicionario.o arvore.o palavra.o

dicionario.o: dicionario.cpp
	g++ dicionario.cpp -c

arvore.o: arvore.cpp
	g++ arvore.cpp -c

palavra.o: palavra.cpp
	g++ palavra.cpp -c

clear:
	del dicionario *.o