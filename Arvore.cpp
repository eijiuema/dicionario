#include "Arvore.hpp"
#include "Palavra.hpp"

Arvore::No::No(Palavra p) {
	this->p = p;
	this->esq = this->dir = nullptr;
	this->alt = 1;
}

Arvore::Arvore() {
	this->raiz = nullptr;
}

Arvore::~Arvore() {

	std::stack<No*> stack;

	Arvore::No *atual;

	stack.push(this->raiz);

	while(!stack.empty()) {

		atual = stack.top();
		stack.pop();

		if(atual->esq != nullptr)
			stack.push(atual->esq);
		if(atual->dir != nullptr)
			stack.push(atual->dir);

		delete atual;
	}

}

bool Arvore::vazia() {
	return this->raiz = nullptr;
}

void Arvore::insere(Palavra p) {
	this->raiz = insereNo(this->raiz, p);
}

void Arvore::remove(Palavra p) {
	this->raiz = removeNo(this->raiz, p);
}

void Arvore::printInOrder() {
	printInOrderNo(this->raiz);
	std::cout << std::endl;
}

Arvore::No *Arvore::insereNo(Arvore::No *raiz, Palavra p) {
	if(raiz == nullptr) {
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

bool Arvore::busca(Palavra p) {
	return buscaNo(this->raiz, p) != nullptr;
}

Arvore::No *Arvore::buscaNo(Arvore::No *raiz, Palavra p) {
	if(raiz == nullptr) {
		return 0;
	} else if(raiz->p == p) {
		return raiz;
	} else if(p < raiz->p) {
		return buscaNo(raiz->esq, p);
	} else {
		return buscaNo(raiz->dir, p);
	}
}

Arvore::No *Arvore::removeNo(Arvore::No *raiz, Palavra p) {
	if(raiz == nullptr) {
		return nullptr;
	} else if(p < raiz->p) {
		raiz->esq = removeNo(raiz->esq, p);
	} else if(p == raiz->p) {
		if(raiz->esq == nullptr || raiz->dir == nullptr) {

			Arvore::No *temp;

			if(raiz->esq == nullptr)
				temp = raiz->dir;

			if(raiz->dir == nullptr)
				temp = raiz->esq;

			if(raiz->dir == nullptr && raiz->esq == nullptr) {
				temp = raiz;
				raiz = nullptr;
			} else {
				*raiz = *temp;
			}

			delete temp;

		} else {

			Arvore::No *menor = menorNo(raiz->dir);

			raiz->p = menor->p;

			raiz->dir = removeNo(raiz->dir, menor->p);

		}

	} else {
		raiz->dir = removeNo(raiz->dir, p);
	}

	if(raiz == nullptr)
		return nullptr;

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

Arvore::No *Arvore::menorNo(Arvore::No *raiz) {
	if(raiz->esq == nullptr) {
		return raiz;
	} else {
		return menorNo(raiz->esq);
	}
}

int Arvore::calcBal(Arvore::No *raiz) {
	if(raiz == nullptr)
		return 0;
	return altura(raiz->esq) - altura(raiz->dir);
}

int Arvore::altura(Arvore::No *raiz) {
	if(raiz == nullptr)
		return 0;
	return raiz->alt;
}

Arvore::No *Arvore::rotE(Arvore::No *raiz) {
	Arvore::No *nova_raiz = raiz->dir;
	Arvore::No *temp = nova_raiz->esq;

	nova_raiz->esq = raiz;
	raiz->dir = temp;

	raiz->alt = 1 + std::max(altura(raiz->esq), altura(raiz->dir));
	nova_raiz->alt = 1 + std::max(altura(nova_raiz->esq), altura(nova_raiz->dir));

	return nova_raiz;
}

Arvore::No *Arvore::rotD(Arvore::No *raiz) {
	Arvore::No *nova_raiz = raiz->esq;
	Arvore::No *temp = nova_raiz->dir;

	nova_raiz->dir = raiz;
	raiz->esq = temp;

	raiz->alt = 1 + std::max(altura(raiz->esq), altura(raiz->dir));
	nova_raiz->alt = 1 + std::max(altura(nova_raiz->esq), altura(nova_raiz->dir));

	return nova_raiz;
}

void Arvore::printInOrderNo(Arvore::No *raiz) {
	if(raiz == nullptr)
		return;

	printInOrderNo(raiz->esq);
	std::cout << raiz->p << ' ';
	printInOrderNo(raiz->dir);
}