#include "Palavra.hpp"

Palavra::Palavra(const std::string palavra) : palavra(palavra)
{ }

Palavra::Palavra(const Palavra& p) : palavra(p.palavra)
{ }

Palavra Palavra::operator=(const Palavra& p)
{
	return Palavra(p.palavra);
}

int Palavra::semelhante(const Palavra& palavra) const
{
	if(this->palavra.substr(0, 2) < palavra.palavra.substr(0, 2)) {
		return -1;
	} else if(this->palavra.substr(0, 2) > palavra.palavra.substr(0, 2)) {
		return 1;
	} else {
		return 0;
	}
}

bool Palavra::operator == (const Palavra& p) const
{
	return palavra == p.palavra;
}

bool Palavra::operator < (const Palavra& p) const
{
	return palavra < p.palavra;
}

bool Palavra::operator > (const Palavra& p) const
{
	return palavra > p.palavra;
}

std::string Palavra::getPalavra() const
{
	return palavra;
}

std::ostream &operator << (std::ostream& os, const Palavra& p)
{
	return os << p.getPalavra();
}

std::string operator + (const std::string string, const Palavra& palavra)
{
	return string + palavra.getPalavra();
}

std::string operator + (const Palavra& palavra, const std::string string)
{
	return palavra.getPalavra() + string;
}