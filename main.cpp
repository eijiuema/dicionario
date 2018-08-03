#include <iostream>
#include "Avl.hpp"
#include "Palavra.hpp"

int main() {

	Avl avl;

	for(int i = 0; i < 5; i++) {
		Palavra p;
		std::cin >> p;
		avl.insere(p);
	}

	avl.printInOrder();
}