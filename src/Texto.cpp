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
	std::stringstream wordBuffer, punctBuffer;
	std::locale loc("");
	std::ifstream inputStream(fn);
	inputStream.imbue(loc);

	if(!inputStream)
		throw std::runtime_error("Could not open file.");

	while(!inputStream.eof())
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
		while(ispunct((char) inputStream.peek(), loc) || isspace((char) inputStream.peek(), loc))
			punctBuffer << (char) inputStream.get();
		// Then go after the word itself
		while(!(isalnum((char) inputStream.peek(), loc) || inputStream.peek() == '-' || inputStream.peek() == '\''))
			wordBuffer << (char) inputStream.get();

		// // After all of this wcreate a safe pointer and store the buffers' info in it
		delimitadores.push_back(punctBuffer.str());
		palavras.emplace_back(new Palavra(wordBuffer.str()));

		// // Clear the buffers' contents so we don't get trash
		punctBuffer.str("");
		wordBuffer.str("");
	}
}

void Texto::salvarArquivo(const std::string& arquivo) const
{
	std::ofstream ofs(arquivo);

	if(!ofs)
		throw std::runtime_error("Could not open file.");

	auto i = 0;
	for(auto &palavra : palavras)
		ofs << delimitadores[i++] << *palavra;
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

std::string Texto::getContexto() const
{
	std::string contexto = "";

	if(iterador > 0)
		contexto = contexto + *palavras[iterador-1];

	contexto+= delimitadores[iterador] + "\"" + *palavras[iterador] + "\"";

	if(iterador < palavras.size() - 2)
		contexto+= delimitadores[iterador+1] + *palavras[iterador+1];

	return contexto;
}