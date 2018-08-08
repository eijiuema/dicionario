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
	bool vazia() const;
	void insere(const Palavra&);
	void remove(const Palavra&);
	bool busca(const Palavra&) const;
	std::vector<Palavra> buscaSemelhantes(const Palavra&) const;
	void printInOrder(std::wostream&) const;
private:
	class No {
	public:
		No(const Palavra&);
		No operator= (const Arvore::No&);
		Palavra p;
		No *esq, *dir;
		int alt;
	};
	No *raiz;
	No *insereNo(No*, const Palavra&);
	No *buscaNo(No*, const Palavra&) const;
	void buscaNoSemelhante(No*, const Palavra&, std::vector<Palavra>&) const;
	No *removeNo(No*, const Palavra&);
	No *menorNo(No*) const;
	int calcBal(No*) const;
	int altura(No*) const;
	No *rotE(No*);
	No *rotD(No*);
	void printInOrderNo(No*, std::wostream&) const;
};

#endif
