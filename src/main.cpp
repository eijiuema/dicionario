#include <iostream>
#include <locale>
#include <vector>
#include "Corretor.hpp"

void exibirMenu()
{
	std::wcout << "\033[2J\033[1;1H"
			   << "[1] Corrigir"				<< std::endl
			   << "[2] Ignorar"					<< std::endl
			   << "[3] Exibir semelhantes" 		<< std::endl
			   << "[4] Adicionar ao dicionário" << std::endl
			   << "[5] Sair"					<< std::endl;
}

int main(void)
{
	setlocale(LC_ALL, "C.UTF-8");

	std::string texto;
	std::wcout << "Digite o caminho para o arquivo do texto (incluindo extensão): ";
	std::cin >> texto;

	exibirMenu();

	Corretor corretor("dic.txt", texto);

	while(corretor.avancarPalavra()) {
		if(!corretor.checarPalavra()) {
			std::wcout << corretor.getContexto() << std::endl;
			corretor.setPalavra(Palavra(L"de"));
			corretor.salvarPalavra();
			std::wcout << corretor.checarPalavra() << std::endl;
		}
	}

	corretor.salvarDicionario();
	corretor.salvarTexto("output.txt");
}