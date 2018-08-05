#include "Texto.hpp"
#include "Palavra.hpp"
#include <iostream>

int main(void)
{
	Palavra palavra1("", "palavra1");
	Palavra palavra2("", "palavra2");
	Palavra palavra3("", "valavra3");
	// Testes:
	// std::cout << palavra1.semelhante(palavra2) << std::endl
	// 	<< palavra2.semelhante(palavra3) << std::endl
	// 	<< (palavra1 == palavra2) << std::endl
	// 	<< (palavra1 < palavra2) << std::endl
	// 	<< (palavra1 > palavra2) << std::endl;
	// Bee movie: (glhf reading the output)
	// Texto texto("bee-movie.txt");
	// auto totalPalavras = texto.getPalavras().size();
	// texto.modificarPalavra(totalPalavras - 3, palavra3);
	// texto.modificarPalavra(totalPalavras - 2, palavra1);
	// texto.modificarPalavra(totalPalavras - 1, palavra2);
	//
	// texto.salvarArquivo(std::cout);

	// char ch;
	// std::cin >> ch;
}
