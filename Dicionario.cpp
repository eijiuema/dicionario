#include "Arvore.hpp"
#include "Palavra.hpp"
#include <ostream>

int main() {

	Arvore arvore;

	for(int i = 0; i < 16534; i++) {
		std::string palavra;
		std::cin >> palavra;
		arvore.insere(Palavra(palavra));
	}

	arvore.printInOrder();
}