#include "Palavra.hpp"

Palavra::Palavra(std::string palavra) {
	this->palavra = palavra;
}

bool operator == (Palavra &p, Palavra &pp) {
	return p.palavra == pp.palavra;
}

bool operator < (Palavra &p, Palavra &pp) {
	return p.palavra < pp.palavra;
}

bool operator > (Palavra &p, Palavra &pp) {
	return p.palavra > pp.palavra;
}

std::ostream &operator << (std::ostream& os, const Palavra &p) {
	os << p.palavra;
	return os;
}

std::istream &operator >> (std::istream& is, Palavra &p) {
	is >> p.palavra;
	return is;
}

