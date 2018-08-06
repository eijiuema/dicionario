#include "Dicionario.hpp"

Dicionario::Dicionario(const std::string& arquivo) : arquivo(arquivo)
{
	std::wifstream inputStream(arquivo);

	inputStream.imbue(std::locale(""));

	if(!inputStream)
		throw std::runtime_error("Could not open file.");

	while(!inputStream.eof()) {
		std::wstring palavra;
		inputStream >> palavra;
		arvore.insere(Palavra(palavra));
	}
}

bool Dicionario::buscaPalavra(const Palavra& palavra) const noexcept
{
	return arvore.busca(palavra);
}

std::vector<Palavra> Dicionario::buscaSemelhantes(const Palavra& palavra) noexcept
{
	return arvore.buscaSemelhantes(palavra);
}