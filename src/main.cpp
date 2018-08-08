#include <iostream>
#include <iomanip>
#include <cmath>
#include <locale>
#include <vector>
#include <codecvt>
#include "Corretor.hpp"

int inputInt(const std::wstring& string, const int comeco, const int final)
{
	std::wcout << string << " [" << comeco << "-" << final << "]: ";
	std::wstring valor;
	std::wcin >> valor;

	try {

		int v = std::stoi(valor);

		if(v < comeco || v > final)
			throw std::out_of_range("");

		return v;

	} catch (std::logic_error& e) {
		std::wcout << L"Insira uma opção válida!" << std::endl;
		return inputInt(string, comeco, final);
	}
}

Corretor inicializarCorretor()
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

	std::wstring texto;
	std::wcout << L"Digite o caminho para o arquivo do texto (incluindo extensão): ";
	std::wcin >> texto;

	try {
		return Corretor("dic.txt", converter.to_bytes(texto));
	} catch(std::runtime_error& e) {
		std::wcout << e.what() << std::endl;
		return inicializarCorretor();
	}
}

int main()
{
	setlocale(LC_ALL, "");

	Corretor corretor = inicializarCorretor();

	do {
		if(!corretor.checarPalavra()) {

			std::wcout << L"\033[2J\033[1;1H";

			menu:

			std::wcout << L"[1] Corrigir"					<< std::endl
					   << L"[2] Ignorar"					<< std::endl
					   << L"[3] Exibir semelhantes" 		<< std::endl
					   << L"[4] Adicionar ao dicionário" 	<< std::endl
					   << L"[5] Sair"						<< std::endl
					   										<< std::endl
					   << corretor.getContexto()			<< std::endl
					   										<< std::endl;

			switch(inputInt(L"Digite o número da opção desejada", 1, 5)) {

				case 1: {
					std::wstring palavra;
					std::wcout << L"Digite a palavra corrigida: ";
					std::wcin >> palavra;
					corretor.setPalavra(Palavra(palavra));
				}

				break;
				case 3: {

					std::vector<Palavra> semelhantes = corretor.buscaSemelhantes();

					if(semelhantes.size() == 0) {
						std::wcout << std::endl << L"Não há palavras semelhantes." << std::endl;
						goto menu;
					}

					int i = 1;
					int digits = std::ceil(std::log10(semelhantes.size()));

					std::wcout << L"Palavras semelhantes: " << std::endl;

					for(auto& semelhante : semelhantes)
						std::wcout << std::setw(digits) << std::setfill(L' ') << i++ << " - " << semelhante << std::endl;

					int palavra = inputInt(L"Digite o número da palavra", 1, semelhantes.size());

					corretor.setPalavra(semelhantes[palavra-1]);
				}

				break;
				case 4:
					corretor.salvarPalavra();
				break;
				case 5:
					goto sair;
				break;
				case 2:
				default:
				break;
			}
		}
	} while(corretor.avancarPalavra());

sair:
	corretor.salvarDicionario();
	std::wcout << L"Digite o nome do arquivo para salvar (deixe vazio para salvar no orignal): ";
	std::wstring path;
	std::wcin >> path;
	corretor.salvarTexto(std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>>().to_bytes(path));
}
