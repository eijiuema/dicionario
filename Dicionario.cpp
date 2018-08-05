#include "Arvore.hpp"
#include "Palavra.hpp"
#include <ostream>

int main() {

	Arvore arvore;

	Palavra p;

	for(int i = 0; i < 16534; i++) {
		std::cin >> p;
		arvore.insere(p);
	}

	arvore.printInOrder();
}