#include <iostream>
#include <locale>
#include <vector>
#include <codecvt>
#include "Corretor.hpp"

int main()
{
	setlocale(LC_ALL, "pt_BR.UTF-8");
	std::locale locale("pt_BR.UTF-8");

	std::wcout.imbue(locale);
	std::wcin.imbue(locale);

	std::wstring texto;

	std::wcout << L"Digite o caminho para o arquivo do texto (incluindo extensão): ";
	std::wcin >> texto;

	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

	try	{

		Corretor corretor("dic.txt", converter.to_bytes(texto));

		while(corretor.avancarPalavra()) {
			if(!corretor.checarPalavra()) {
				std::wcout << L"\033[2J\033[1;1H"
						   << L"[1] Corrigir"					<< std::endl
						   << L"[2] Ignorar"					<< std::endl
						   << L"[3] Exibir semelhantes" 		<< std::endl
						   << L"[4] Adicionar ao dicionário" 	<< std::endl
						   << L"[5] Sair"						<< std::endl
						   										<< std::endl
						   << corretor.getContexto()			<< std::endl
						   										<< std::endl
						   << L"Digite o número da opção desejada [1-5]: ";

				std::wstring opcao;
				std::wcin >> opcao;

				switch(opcao[0]) {

					case '1': {
						std::wstring palavra;
						std::wcout << "Digite a palavra corrigida: ";
						std::wcin >> palavra;
						corretor.setPalavra(Palavra(palavra));
					}

					break;
					case '2':
					break;
					case '3':
					break;
					case '4':
					break;
					case '5':
					break;
					default:
					break;
				}
			}
		}

		corretor.salvarDicionario();
		corretor.salvarTexto("output.txt");

	} catch(std::runtime_error& e) {
		std::wcout << e.what() << std::endl;
	}
}