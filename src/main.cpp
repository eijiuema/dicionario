#include <iostream>
#include <locale>
#include <vector>
#include <cctype>
#include "Corretor.hpp"

int main()
{
	setlocale(LC_ALL, "C.UTF-8");
	// std::cout << "Árvore" << std::endl;
	// std::string arvore;
	// std::cin >> arvore;
	// std::cout << arvore << std::endl;

	// std::ifstream arquivo("dic.txt");

	// if(arquivo)
	// 	while(!arquivo.eof())
	// 		std::cout << (char) arquivo.get();
	// return 0;

	std::string texto;
	std::cout << "Digite o caminho para o arquivo do texto (incluindo extensão): ";
	std::cin >> texto;

	// try	{

		Corretor corretor("dic.txt", (std::string) texto);

		while(corretor.avancarPalavra()) {
			if(!corretor.checarPalavra()) {
				std::cout << "\033[2J\033[1;1H"
						   << "[1] Corrigir"				<< std::endl
						   << "[2] Ignorar"					<< std::endl
						   << "[3] Exibir semelhantes" 		<< std::endl
						   << "[4] Adicionar ao dicionário" << std::endl
						   << "[5] Sair"					<< std::endl
						   									<< std::endl
						   << corretor.getContexto()		<< std::endl
						   									<< std::endl
						   << "Digite o número da opção desejada [1-5]: ";

				std::string opcao;
				std::cin >> opcao;

				switch(opcao[0]) {
					case '1':
					default:
					break;
				}
			}
		}

		corretor.salvarTexto("output.txt");

	// 	// exibirMenuFinal();

	// 	corretor.salvarDicionario();
	// 	corretor.salvarTexto("output.txt");

	// } catch(std::runtime_error& e) {

	// }
}