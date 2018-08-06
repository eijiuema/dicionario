#ifndef AVL
#define AVL

#include <iostream>
#include <stack>
#include <vector>
#include "Palavra.hpp"

class Arvore {
public:
	Arvore();
	~Arvore();
	bool vazia();
	void insere(const Palavra& p);
	void remove(const Palavra& p);
	bool busca(const Palavra& p) const;
	std::vector<Palavra> buscaSemelhante(const Palavra& p);
	void printInOrder();
private:
	std::vector<Palavra> semelhantes;
	class No {
	public:
		No(const Palavra& p);
		No operator= (const Arvore::No& no);
		Palavra p;
		No *esq, *dir;
		int alt;
	};
	No *raiz;
	No *insereNo(No *raiz, const Palavra& p);
	No *buscaNo(No *raiz, const Palavra& p) const;
	void buscaNoSemelhante(No *raiz, const Palavra& p);
	No *removeNo(No *raiz, const Palavra& p);
	No *menorNo(No *raiz);
	int calcBal(No *raiz);
	int altura(No *raiz);
	No *rotE(No *raiz);
	No *rotD(No *raiz);
	void printInOrderNo(No *raiz);
};

#endif
