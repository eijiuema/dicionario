#include "Corretor.hpp"

Corretor::Corretor(std::string dicionario, std::string texto) : dicionario(dicionario), texto(texto)
{ }

bool Corretor::avancarPalavra()
{
	return texto.avancarPalavra();
}

bool Corretor::checarPalavra()
{
	Palavra palavra = texto.getPalavra();

	if(!dicionario.buscaPalavra(palavra)) {

		auto it = erros.find(palavra);

		if(it == erros.end()) {
			erros[palavra] = 0;
		}

		erros[palavra]++;

		return false;
	}

	return true;
}

void Corretor::setPalavra(const Palavra& palavra)
{
	texto.setPalavra(palavra);
}

void Corretor::salvarPalavra()
{
	dicionario.inserePalavra(texto.getPalavra());
}

std::wstring Corretor::getContexto() const
{
	return texto.getContexto();
}

std::vector<Palavra> Corretor::buscaSemelhantes() const
{
	return dicionario.buscaSemelhantes(texto.getPalavra());
}

void Corretor::salvarTexto(const std::string& arquivo) const
{
	texto.salvarArquivo(arquivo);
}

void Corretor::salvarDicionario() const
{
	dicionario.salvarArquivo();
}

std::map<Palavra, int> Corretor::getErros() const
{
	return erros;
}