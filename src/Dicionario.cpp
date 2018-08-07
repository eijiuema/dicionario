#include "Dicionario.hpp"

Dicionario::Dicionario(const std::string& arquivo) : arquivo(arquivo)
{
	std::ifstream inputStream(arquivo);

	inputStream.imbue(std::locale(""));

	if(!inputStream)
		throw std::runtime_error("Could not open file.");

	while(!inputStream.eof()) {
		std::string palavra;
		inputStream >> palavra;
		arvore.insere(Palavra(palavra));
	}
}

void Dicionario::inserePalavra(const Palavra& palavra)
{
	arvore.insere(palavra);
}

bool Dicionario::buscaPalavra(const Palavra& palavra) const noexcept
{
	return arvore.busca(palavra);
}

std::vector<Palavra> Dicionario::buscaSemelhantes(const Palavra& palavra) const noexcept
{
	return arvore.buscaSemelhantes(palavra);
}

void Dicionario::salvarArquivo() const
{
	std::ofstream wofs(arquivo);

	wofs.imbue(std::locale(""));

	if(!wofs)
		throw std::runtime_error("Could not open file.");

	arvore.printInOrder(wofs);
}