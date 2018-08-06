#include "Dicionario.hpp"

Dicionario::Dicionario(const std::string& arquivo) : arquivo(arquivo)
{
	std::ifstream inputStream(arquivo);

	if(inputStream.bad() || (int)inputStream.tellg() == -1)
		throw std::runtime_error("Could not open file.");

	while(!inputStream.eof()) {
		std::string palavra;
		inputStream >> palavra;
		arvore.insere(Palavra(palavra));
	}

	arvore.printInOrder();
}

bool Dicionario::buscaPalavra(const Palavra& palavra) const noexcept
{
	return arvore.busca(palavra);
}

std::vector<Palavra> Dicionario::buscaSemelhantes(const Palavra& palavra) const noexcept
{

}