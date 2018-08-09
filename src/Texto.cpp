#include "Texto.hpp"
#include <exception>
#include <iostream>
#include <sstream>
#include <locale>

Texto::Texto(const char* fn) : Texto(std::string(fn))
{ }

Texto::Texto(const std::string &fn) : nomeArquivo(fn), iterador(0), delimitadores(), palavras()
{
	int lastPos = -1;
	std::wstringstream wordBuffer, punctBuffer;
	std::locale loc("");
	std::wifstream inputStream(fn);
	inputStream.imbue(loc);

	if(!inputStream)
		throw std::runtime_error("Erro ao abrir o arquivo.");

	if(inputStream.peek() == std::wifstream::traits_type::eof())
		throw std::runtime_error("Arquivo vazio.");


	while(inputStream.peek() != std::wifstream::traits_type::eof())
	{
		if(lastPos == inputStream.tellg())
		{
			std::cerr << "Stuck on letter '" << (char)inputStream.peek() << "' (offset"
			<< std::hex << inputStream.tellg() << std::dec << ")" << std::endl;
			std::cerr.flush();
			throw std::runtime_error("Stuck on letter.");
		}

		lastPos = inputStream.tellg();

		// Read all leading punctuation and spaces
		while(ispunct((wchar_t) inputStream.peek(), loc) || isspace((char) inputStream.peek(), loc))
			punctBuffer << (wchar_t) inputStream.get();
		// Then go after the word itself
		while(isalnum((wchar_t) inputStream.peek(), loc) || inputStream.peek() == '-' || inputStream.peek() == '\'')
			wordBuffer << (wchar_t) inputStream.get();

		// After all of this wcreate a safe pointer and store the buffers' info in it
		delimitadores.push_back(punctBuffer.str());

		if(!wordBuffer.str().empty())
			palavras.emplace_back(new Palavra(wordBuffer.str()));

		// Clear the buffers' contents so we don't get trash
		punctBuffer.str(L"");
		wordBuffer.str(L"");
	}
}

void Texto::salvarArquivo(const std::string& arquivo) const
{
	std::wofstream outputStream(arquivo);

	outputStream.imbue(std::locale(""));

	if(!outputStream)
		throw std::runtime_error("Erro ao salvar o arquivo.");

	size_t i = 0;
	for(auto &palavra : palavras)
		outputStream << delimitadores[i++] << *palavra;

	if(i < delimitadores.size())
		outputStream << delimitadores[i];
}

bool Texto::avancarPalavra()
{
	if(iterador < palavras.size() - 1) {
		iterador++;
		return true;
	} else {
		return false;
	}
}

Palavra Texto::getPalavra() const
{
	return *palavras[iterador];
}

void Texto::setPalavra(const Palavra& palavra)
{
	palavras[iterador].reset(new Palavra(palavra));
}

std::wstring Texto::getContexto() const
{
	std::wstring contexto = L"";

	if(iterador > 0)
		contexto+= delimitadores[iterador-1] + *palavras[iterador-1];

	contexto+=  delimitadores[iterador] + L"\"" + *palavras[iterador] + L"\"";

	if(iterador < palavras.size() - 1)
		contexto+= delimitadores[iterador+1] + *palavras[iterador+1];

	if(iterador == palavras.size() - 1)
		contexto+= delimitadores[iterador+1];

	return contexto;
}
