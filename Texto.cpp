#include "Texto.hpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <cctype>
#include <exception>

Texto::Texto(const char* fn) : Texto(std::string(fn))
{ }

Texto::Texto(const std::string &fn) : nomeArquivo(fn), palavras()
{
	std::stringstream wordBuffer, punctBuffer;
	std::ifstream inputStream(fn);
	while(!inputStream.eof())
	{
		// Read all leading punctuation and spaces
		while(ispunct(inputStream.peek()) || isspace(inputStream.peek()))
			punctBuffer << (char) inputStream.get();
		// Then go after the word itself
		while(isalnum(inputStream.peek()) || inputStream.peek() == '-' || inputStream.peek() == '\'')
			wordBuffer << (char) inputStream.get();

		// After all of this create a safe pointer and store the buffers' info in it
		this->palavras.emplace_back(new Palavra(punctBuffer.str(), wordBuffer.str()));

		// Clear the buffers' contents so we don't get trash
		punctBuffer.str("");
		wordBuffer.str("");
	}
	// Shrink the vector so that it only uses the necessary space
	this->palavras.shrink_to_fit();
}

void Texto::salvarArquivo(std::ostream& outputStream) const
{
	for(auto &palavra : this->palavras)
		palavra->escreverPalavra(outputStream);
}

void Texto::modificarPalavra(const int& pos, const Palavra& palavra)
{
	if(pos < 0 || pos > this->palavras.size())
		throw new std::runtime_error("Posição da palavra está fora do vetor.");
	this->palavras[pos]->modificarPalavra(palavra.getPalavra());
}

const VetorPalavras& Texto::getPalavras() const
{
	return this->palavras;
}
