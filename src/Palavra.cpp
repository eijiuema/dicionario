#include "Palavra.hpp"

Palavra::Palavra(const std::wstring palavra) : palavra(palavra)
{ }

Palavra::Palavra(const Palavra& p) : palavra(p.palavra)
{ }

Palavra Palavra::operator=(const Palavra& p)
{
	return Palavra(p.palavra);
}

bool Palavra::semelhante(const Palavra& palavra) const
{
	return this->palavra[0] == palavra.palavra[0]
		&& this->palavra[1] == palavra.palavra[1];
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

std::wstring Palavra::getPalavra() const
{
	return palavra;
}

std::wostream &operator << (std::wostream& wos, const Palavra& p)
{
	return wos << p.getPalavra();
}