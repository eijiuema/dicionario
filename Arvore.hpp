#ifndef AVL
#define AVL

#include <iostream>
#include <stack>
#include "Palavra.hpp"


class Arvore {
public:
	Arvore();
	~Arvore();
	bool vazia();
	void insere(Palavra p);
	void remove(Palavra p);
	bool busca(Palavra p);
	void printInOrder();
private:
	class No {
	public:
		Palavra p;
		No(Palavra p);
		No *esq, *dir;
		int alt;
	};
	No *raiz;
	No *insereNo(No *raiz, Palavra p);
	No *buscaNo(No *raiz, Palavra p);
	No *removeNo(No *raiz, Palavra p);
	No *menorNo(No *raiz);
	int calcBal(No *raiz);
	int altura(No *raiz);
	No *rotE(No *raiz);
	No *rotD(No *raiz);
	void printInOrderNo(No *raiz);
};

#endif