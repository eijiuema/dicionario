#ifndef AVL
#define AVL

#include "Palavra.hpp";

class No {
public:
	Palavra *p;
	No(Palavra *);
	No *esq, *dir;
	int bal;
	~No();
private:
}

class Avl {
public:
	bool vazia();
	void insere(Palavra *);
	void remove(Palavra *);
	Palavra busca(Palavra *);
	~Avl();
private:
	No *raiz;
	No *balancear(No *);
	No *rotE(No *);
	No *rotD(No *);
	No *rotED(No *);
	No *rotDE(No *);
	int altura(No *);
};

#endif