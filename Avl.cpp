#include "Palavra.hpp";

No::No(Palavra p = NULL) {
	this.palavra = p;
	this.esq = NULL;
	this.dir = NULL;
	this.alt = 0;
}

Avl::Avl() {
	this.raiz = NULL;
}

Avl::~Avl() {

	std::stack<No*> stack;

	No *atual;

	stack.push(this.raiz);

	while(!stack.empty()) {

		atual = stack.top();
		stack.pop();

		if(atual->esq != NULL)
			stack.push(atual->esq);
		if(atual->dir != NULL)
			stack.push(atual->dir);

		delete atual;
	}

	delete this;

}

bool Avl::vazia() {
	return this.raiz = NULL;
}

void Avl::insere(Palavra *p) {
	if(this.vazia()) {
		this.raiz = new No(p);
	} else {
		insereNo(this.raiz, new No(p));
	}
}

No *Avl::insereNo(No *raiz, No *no) {
	if(&(no->p) < &(raiz->p)) {
		if(raiz->esq != NULL) {
			insereNo(raiz->esq, no);
		} else {
			raiz->esq = no;
		}
	} else {
		if(raiz->dir != NULL) {
			insereNo(raiz->dir, no);
		} else {
			raiz->dir = no;
		}
	}

	raiz = balancear(raiz);
}

No *Avl::busca(Palavra p) {
	return buscaNo(this.raiz, p);
}

No *Avl::buscaNo(No *raiz, Palavra p) {
	if(raiz == NULL) {
		return NULL;
	} else if(&(raiz->p) == p) {
		return raiz;
	} else if(p < &(raiz->p)) {
		return buscaNo(raiz->esq, p);
	} else {
		return buscaNo(raiz->dir, p);
	}
}

void Avl::remove(Palavra p) {
	this.raiz = removeNo(this.raiz, p);
}

No *Avl::removeNo(No *raiz, Palavra p) {
	if(raiz == NULL) {
		return NULL;
	} else if(p < &(raiz->p)) {
		return removeNo(raiz->esq, p);
	} else if(p == &(raiz->p)) {
		if(raiz->esq == NULL) {
			No *temp = raiz->dir;
			delete raiz;
			return temp;
		} else if(raiz->dir == NULL) {
			No *temp = raiz->esq;
			delete raiz;
			return temp;
		}

		No *menor = menorNo(raiz->dir);
		raiz->p = menor->p;
		raiz->dir = removeNo(raiz->dir, menor->p);

		balancear(raiz);

		return raiz;
	} else {
		return removeNo(raiz->dir, p);
	}
}

No *Avl::menorNo(No *raiz) {
	if(raiz->esq == NULL) {
		return raiz;
	} else {
		return menorNo(raiz->esq);
	}
}

No *Avl::balancear(No *raiz) {

}

int Avl::altura(No *raiz) {
	if(raiz == NULL) {
		return 0;
	} else {
		return std::max(altura(raiz->esq), altura(raiz->dir));
	}

}