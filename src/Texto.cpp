#include "Texto.hpp"
#include <exception>
#include <iostream>
#include <sstream>
#include <cctype>
#ifdef TIME_TEXTO
#	include "Timer.hpp"
#endif

Texto::Texto(const char* fn) : Texto(std::string(fn))
{ }

Texto::Texto(const std::string &fn) : nomeArquivo(fn), delimitadores(), palavras()
{
#ifdef TIME_TEXTO
	double wordAvg = 0;
	Timer::start("Texto::_ctor");
#endif
	int lastPos = -1;
	std::stringstream wordBuffer, punctBuffer;
	std::ifstream inputStream(fn);

#ifdef TIME_TEXTO
	Timer::start("Texto::_ctor loop");
#endif
	if(inputStream.bad() || (int)inputStream.tellg() == -1)
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
		// Read all leading punctuation and spaces
		while(ispunct(inputStream.peek()) || isspace(inputStream.peek()))
			punctBuffer << (char) inputStream.get();
		// Then go after the word itself
		while(isalnum(inputStream.peek()) || inputStream.peek() == '-' || inputStream.peek() == '\'')
			wordBuffer << (char) inputStream.get();

		// After all of this create a safe pointer and store the buffers' info in it
		delimitadores.push_back(punctBuffer.str());
		// palavras.emplace_back(new Palavra(wordBuffer.str()));

		// Clear the buffers' contents so we don't get trash
		punctBuffer.str("");
		wordBuffer.str("");
	}
#ifdef TIME_TEXTO
	wordAvg = (Timer::elapsed<Timer::us>("Texto::_ctor loop") / (double) palavras.size()).count();
#endif

	// Shrink the vector so that it only uses the necessary space
	delimitadores.shrink_to_fit();
	palavras.shrink_to_fit();

#ifdef TIME_TEXTO
		std::cerr << Timer::elapsed<Timer::us>("Texto::_ctor").count()
			<< "μs elapsed parsing the whole file, with an average of "
			<< wordAvg << "μs per word." << std::endl;
#endif
}

void Texto::salvarArquivo(std::ostream& outputStream) const noexcept
{
	auto i = 0;
	for(auto &palavra : palavras)
		outputStream << delimitadores[i++] << *palavra;
}

void Texto::modificarPalavra(const int& pos, const Palavra& palavra)
{
	if(pos < 0 || pos > palavras.size())
		throw new std::runtime_error("Posição da palavra está fora do vetor.");
	// Replace the old word by a copy of the new word
	palavras[pos].reset(new Palavra(palavra));
}

const std::vector<std::unique_ptr<Palavra>>& Texto::getPalavras() const noexcept
{
	return palavras;
}
