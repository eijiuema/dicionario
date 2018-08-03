#include "Palavra.hpp"

Palavra::Palavra(std::string delimitadores, std::string palavra) : delimitadores(delimitadores), palavra(palavra)
{ }

bool Palavra::semelhante(Palavra palavra) const
{
	return this->palavra[0] == palavra.palavra[0]
		&& this->palavra[1] == palavra.palavra[1];
}

void Palavra::escreverPalavra(std::ostream &outputStream) const
{
	outputStream << this->delimitadores;
	outputStream << this->palavra;
}

std::string Palavra::getPalavra() const
{
	return this->palavra;
}

std::string Palavra::getDelimitadores() const
{
	return this->delimitadores;
}

void Palavra::modificarPalavra(std::string palavra)
{
	this->palavra = palavra;
}

bool Palavra::operator == (Palavra palavra) const
{
	return this->palavra == palavra.palavra;
}

bool Palavra::operator < (Palavra palavra) const
{
	return this->palavra < palavra.palavra;
}

bool Palavra::operator > (Palavra palavra) const
{
	return this->palavra > palavra.palavra;
}
