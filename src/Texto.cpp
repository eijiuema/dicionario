#include "Texto.hpp"
#include <exception>
#include <iostream>
#include <sstream>
#include <locale>

Texto::Texto(const char* fn) : Texto(std::string(fn))
{ }

Texto::Texto(const std::string &fn) : nomeArquivo(fn), delimitadores(), palavras()
{
	int lastPos = -1;
	std::wstringstream wordBuffer, punctBuffer;
	std::locale loc("C.UTF-8");
	std::wifstream inputStream(fn);
	inputStream.imbue(loc);

	if(!inputStream)
		throw std::runtime_error("Could not open file.");

	while(!inputStream.eof())
	{
		if(lastPos == inputStream.tellg())
		{
			std::wcerr << L"Stuck on letter '" << (char)inputStream.peek() << L"' (offset"
			<< std::hex << inputStream.tellg() << std::dec << L")" << std::endl;
			std::wcerr.flush();
			throw std::runtime_error("Stuck on letter.");
		}
		// Read all leading punctuation and spaces
		while(ispunct((wchar_t) inputStream.peek(), loc) || isspace((wchar_t) inputStream.peek(), loc))
			punctBuffer << (char) inputStream.get();
		// Then go after the word itself
		while(isalnum((wchar_t) inputStream.peek(), loc) || inputStream.peek() == '-' || inputStream.peek() == '\'')
			wordBuffer << (char) inputStream.get();

		// After all of this wcreate a safe pointer and store the buffers' info in it
		delimitadores.push_back(punctBuffer.str());
		palavras.emplace_back(new Palavra(wordBuffer.str()));

		// Clear the buffers' contents so we don't get trash
		punctBuffer.str(L"");
		wordBuffer.str(L"");
	}
}

void Texto::salvarArquivo(const std::string& arquivo) const
{
	std::wofstream wofs(arquivo);

	if(!wofs)
		throw std::runtime_error("Could not open file.");

	auto i = 0;
	for(auto &palavra : palavras)
		wofs << delimitadores[i++] << *palavra;
}

bool Texto::avancarPalavra()
{
	if(iterador < palavras.size() - 2) {
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
		contexto = contexto + *palavras[iterador-1];

	contexto+= delimitadores[iterador] + L"\"" + *palavras[iterador] + L"\"";

	if(iterador < palavras.size() - 2)
		contexto+= delimitadores[iterador+1] + *palavras[iterador+1];

	return contexto;
}