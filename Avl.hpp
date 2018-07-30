#ifndef AVL
#define AVL

#include "Palavra.hpp";

class No {
public:
	No();
	Palavra *p;
	No *esq, *dir;
	int bal;
	~No();
}

class Avl {
public:
	Avl();
	bool vazia();
	bool insere(Palavra *);
	bool remove(Palavra *);
	Palavra busca(Palavra *);
	~Avl();
private:
	int bal(No *);
	No *rotEE(No *);
	No *rotDD(No *);
	No *rotED(No *);
	No *rotDE(No *);
};

#endif