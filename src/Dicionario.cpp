#include "Dicionario.hpp"

Dicionario::Dicionario(const std::string& arquivo) : arquivo(arquivo)
{
	std::wifstream inputStream(arquivo);

	inputStream.imbue(std::locale(""));

	if(!inputStream)
		throw std::runtime_error("Erro ao abrir o arquivo.");

	while(!inputStream.eof()) {
		std::wstring palavra;
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
	std::wofstream outputStream(arquivo);

	outputStream.imbue(std::locale(""));

	if(!outputStream)
		throw std::runtime_error("Could not open file.");

	arvore.print(Arvore::print_order::level, outputStream);
}