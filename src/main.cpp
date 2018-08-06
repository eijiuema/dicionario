#include "Texto.hpp"
#include "Palavra.hpp"
#include "Timer.hpp"
#include "Dicionario.hpp"
#include <iostream>
#include <locale>
#include <vector>

int main(void)
{
	setlocale(LC_ALL, "C.UTF-8");
	Dicionario dicionario("dic.txt");

	std::vector<Palavra> semelhantes = dicionario.buscaSemelhantes(Palavra(L"abacaxi"));

	for(auto &palavra : semelhantes)
		std::wcout << palavra.getPalavra() << std::endl;

	// Palavra palavra1("palavra1");
	// Palavra palavra2("palavra2");
	// Palavra palavra3("valavra3");
	// Palavra empty("");
	// // Testes:
	// std::cout << palavra1.semelhante(palavra2) << std::endl
	// 	<< palavra2.semelhante(palavra3) << std::endl
	// 	<< (palavra1 == palavra2) << std::endl
	// 	<< (palavra1 < palavra2) << std::endl
	// 	<< (palavra1 > palavra2) << std::endl;
	// // Bee movie: (glhf reading the output)
	// try
	// {
	// 	Texto texto("bee-movie.txt");
	// 	std::ofstream output("output.txt");
	// 	Timer::start("main salvarArquivo");
	// 	texto.salvarArquivo(output);
	// 	std::cout << Timer::elapsed<Timer::us>("main salvarArquivo").count()
	// 		<< "μs elapsed saving the file." << std::endl;
	// }
	// catch(std::runtime_error &err)
	// {
	// 	std::cerr << err.what();
	// 	return 1;
	// }
}
