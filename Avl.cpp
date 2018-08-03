#include "Avl.hpp"
#include "Palavra.hpp"

No::No(Palavra p) {
	this->p = p;
	this->esq = this->dir = NULL;
	this->alt = 1;
}

Avl::Avl() {
	this->raiz = NULL;
}

Avl::~Avl() {

	std::stack<No*> stack;

	No *atual;

	stack.push(this->raiz);

	while(!stack.empty()) {

		atual = stack.top();
		stack.pop();

		if(atual->esq != NULL)
			stack.push(atual->esq);
		if(atual->dir != NULL)
			stack.push(atual->dir);

		delete atual;
	}

}

bool Avl::vazia() {
	return this->raiz = NULL;
}

void Avl::insere(Palavra p) {
	this->raiz = insereNo(this->raiz, p);
}

void Avl::remove(Palavra p) {
	this->raiz = removeNo(this->raiz, p);
}

void Avl::printInOrder() {
	printInOrderNo(this->raiz);
	std::cout << std::endl;
}

No *Avl::insereNo(No *raiz, Palavra p) {
	if(raiz == NULL) {
		return new No(p);
	} else if(p < raiz->p) {
		raiz->esq = insereNo(raiz->esq, p);
	} else if(p > raiz->p) {
		raiz->dir = insereNo(raiz->dir, p);
	} else {
		return raiz;
	}

	raiz->alt = 1 + std::max(altura(raiz->esq), altura(raiz->dir));

	int bal = calcBal(raiz);

	if(bal > 1) { // Desbalanceado à esquerda
		if(p < raiz->esq->p) { // Nó esquerdo
			return rotD(raiz);
		} else { // Nó direito
			raiz->esq = rotE(raiz->esq);
			return rotD(raiz);
		}
	} else if(bal < -1) { // Desbalanceado à direita
		if(p < raiz->dir->p) { // Nó esquerdo
			raiz->dir = rotD(raiz->dir);
			return rotE(raiz);
		} else { // Nó direito
			return rotE(raiz);
		}
	}

	return raiz;
}

bool Avl::busca(Palavra p) {
	return buscaNo(this->raiz, p) != NULL;
}

No *Avl::buscaNo(No *raiz, Palavra p) {
	if(raiz == NULL) {
		return 0;
	} else if(raiz->p == p) {
		return raiz;
	} else if(p < raiz->p) {
		return buscaNo(raiz->esq, p);
	} else {
		return buscaNo(raiz->dir, p);
	}
}

No *Avl::removeNo(No *raiz, Palavra p) {
	if(raiz == NULL) {
		return NULL;
	} else if(p < raiz->p) {
		raiz->esq = removeNo(raiz->esq, p);
	} else if(p == raiz->p) {
		if(raiz->esq == NULL || raiz->dir == NULL) {

			No *temp;

			if(raiz->esq == NULL)
				temp = raiz->dir;

			if(raiz->dir == NULL)
				temp = raiz->esq;

			if(raiz->dir == NULL && raiz->esq == NULL) {
				temp = raiz;
				raiz = NULL;
			} else {
				*raiz = *temp;
			}

			delete temp;

		} else {

			No *menor = menorNo(raiz->dir);

			raiz->p = menor->p;

			raiz->dir = removeNo(raiz->dir, menor->p);

		}

	} else {
		raiz->dir = removeNo(raiz->dir, p);
	}

	if(raiz == NULL)
		return NULL;

	raiz->alt = 1 + std::max(altura(raiz->esq), altura(raiz->dir));

	int bal = calcBal(raiz);

	if(bal > 1) { // Desbalanceada à esquerda
		if(calcBal(raiz->esq) < 0) { // Subárvore esquerda tendendo a direita
			raiz->esq = rotE(raiz->esq);
			return rotD(raiz);
		} else { // Subárvore a direita tendendo a esquerda ou balanceada
			return rotD(raiz);
		}
	} else if(bal < -1)  { // Desbalanceada à direita
		if(calcBal(raiz->dir) > 0) { // Subárvore direita tendendo a esquerda
			raiz->dir = rotD(raiz->dir);
			return rotE(raiz);
		} else { // Subárvore direita tendendo a direita ou balanceada
			return rotE(raiz);
		}
	}

	return raiz;
}

No *Avl::menorNo(No *raiz) {
	if(raiz->esq == NULL) {
		return raiz;
	} else {
		return menorNo(raiz->esq);
	}
}

int Avl::calcBal(No *raiz) {
	if(raiz == NULL)
		return 0;
	return altura(raiz->esq) - altura(raiz->dir);
}

int Avl::altura(No *raiz) {
	if(raiz == NULL)
		return 0;
	return raiz->alt;
}

No *Avl::rotE(No *raiz) {
	No *nova_raiz = raiz->dir;
	No *temp = nova_raiz->esq;

	nova_raiz->esq = raiz;
	raiz->dir = temp;

	raiz->alt = 1 + std::max(altura(raiz->esq), altura(raiz->dir));
	nova_raiz->alt = 1 + std::max(altura(nova_raiz->esq), altura(nova_raiz->dir));

	return nova_raiz;
}

No *Avl::rotD(No *raiz) {
	No *nova_raiz = raiz->esq;
	No *temp = nova_raiz->dir;

	nova_raiz->dir = raiz;
	raiz->esq = temp;

	raiz->alt = 1 + std::max(altura(raiz->esq), altura(raiz->dir));
	nova_raiz->alt = 1 + std::max(altura(nova_raiz->esq), altura(nova_raiz->dir));

	return nova_raiz;
}

void Avl::printInOrderNo(No *raiz) {
	if(raiz == NULL)
		return;

	printInOrderNo(raiz->esq);
	std::cout << raiz->p << ' ';
	printInOrderNo(raiz->dir);
}