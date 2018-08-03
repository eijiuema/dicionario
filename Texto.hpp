#ifndef TEXTO_H
#define TEXTO_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include "Palavra.hpp"

typedef std::vector<std::unique_ptr<Palavra>> VetorPalavras;

class Texto
{
private:
	std::string nomeArquivo;
	VetorPalavras palavras;
public:
	Texto(const char*);
	Texto(const std::string &);

	void salvarArquivo(std::ostream &) const;
	void modificarPalavra(const int &, const Palavra &);
	const VetorPalavras& getPalavras() const;
};

#endif
