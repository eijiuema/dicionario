#include "Palavra.hpp"

Palavra::Palavra(std::string palavra) {
	this->palavra = palavra;
}

bool operator == (const Palavra &p, const Palavra &pp) {
	return p.palavra == pp.palavra;
}

bool operator < (const Palavra &p, const Palavra &pp) {
	const std::collate<char>& collate =
		std::use_facet<std::collate<char>>(std::locale());

	return collate.compare(p.palavra.data(), p.palavra.data() + p.palavra.size(),
						   pp.palavra.data(), pp.palavra.data() + pp.palavra.size()) < 0;
}

bool operator > (const Palavra &p, const Palavra &pp) {
	return pp < p;
}

std::ostream &operator << (std::ostream& os, const Palavra &p) {
	os << p.palavra;
	return os;
}

std::istream &operator >> (std::istream& is, Palavra &p) {
	is >> p.palavra;
	return is;
}

