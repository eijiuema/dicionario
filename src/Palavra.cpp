#include "Palavra.hpp"

Palavra::Palavra(const std::wstring palavra) : palavra(palavra)
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

Palavra Palavra::minuscula() const
{
	std::wstring minuscula = palavra;
	std::transform(palavra.begin(), palavra.end(), minuscula.begin(), ::towlower);
	return Palavra(minuscula);
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

std::wostream &operator << (std::wostream& outputStream, const Palavra& p)
{
	return outputStream << p.getPalavra();
}

std::wstring operator + (const std::wstring string, const Palavra& palavra)
{
	return string + palavra.getPalavra();
}

std::wstring operator + (const Palavra& palavra, const std::wstring string)
{
	return palavra.getPalavra() + string;
}
