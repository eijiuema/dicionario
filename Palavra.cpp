#include "Palavra.hpp"

Palavra::Palavra(const std::string palavra), palavra(palavra)
{ }

bool Palavra::semelhante(Palavra palavra) const
{
	return this->palavra[0] == palavra.palavra[0]
		&& this->palavra[1] == palavra.palavra[1];
}

bool operator == (const Palavra &p, const Palavra &pp) {
	return p.palavra == pp.palavra;
}

bool operator < (const Palavra &p, const Palavra &pp) {
	return p.palavra < pp.palavra;
}

bool operator > (const Palavra &p, const Palavra &pp) {
	return p.palavra > pp.palavra;
}


std::ostream &operator << (std::ostream& os, const Palavra &p) {
	return os << p.palavra;
}

std::istream &operator >> (std::istream& is, Palavra &p) {
	return is >> p.palavra;
}