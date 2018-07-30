#include "Palavra.hpp";

No::No(Palavra *p = NULL) {
	this.palavra = p;
	this.esq = NULL;
	this.dir = NULL;
	this.bal = 0;
}

No::~No() {
	if(this.esq != NULL)
		delete this.esq;

	if(this.dir != NULL)
		delete this.dir;

	delete this;
}

Avl::Avl() {
	this.raiz = NULL;
}

Avl::~Avl() {
	delete this.raiz;
	delete this;
}

bool Avl::vazia() {
	return this.raiz = NULL;
}

void Avl::insere(Palavra *p) {

	if(this.vazia()) {
		this.raiz = new No(p);
	} else {
		std::stack<No*> stack;

		stack.push(this.raiz);

		No *atual;

		while(!stack.empty()) {

			atual = stack.top();

			stack.pop();

			if(no->esq != NULL && &p < &(no->esq->p))  {
				stack.push(no->esq);
			} else if(no->dir != NULL && &p > &(no->dir->p)) {
				stack.push(no->dir);
			}

		}

		if(&p < &(atual.p)) {
			atual.esq = new No(p);
		} else {
			atual.dir = new No(p);
		}

		this.raiz = this.balancear(this.raiz);
	}

}

No *Avl::balancear(No *raiz) {

}

No *Avl::remover(Palavra *p) {
	No *removido = this.busca(p);

	if(removido.esq != NULL)
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
	No *raiz;
	int altura(No *);
	int bal(No *);
	No *rotE(No *);
	No *rotD(No *);
	No *rotED(No *);
	No *rotDE(No *);
};