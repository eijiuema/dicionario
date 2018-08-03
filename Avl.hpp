#ifndef AVL
#define AVL

#include "Palavra.hpp";

class No {
public:
	Palavra p;
	No(Palavra p);
	No *esq, *dir;
	int alt;
private:
};

class Avl {
public:
	bool vazia();
	void insere(Palavra *p);
	void remove(Palavra p);
	Palavra busca(Palavra p);
	Avl();
	~Avl();
private:
	No *raiz;
	No *insereNo(No *raiz, No *no);
	No *buscaNo(No *raiz, Palavra p);
	No *removeNo(No *raiz, No *no);
	No *menorNo(No *raiz);
	No *balancear(No *);
	No *rotE(No *);
	No *rotD(No *);
	No *rotED(No *);
	No *rotDE(No *);
};

#endif
