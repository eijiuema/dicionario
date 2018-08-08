#ifndef TEXTO_H
#define TEXTO_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include "Palavra.hpp"

class Texto
{
private:
	std::string nomeArquivo;
	int iterador = 0;
	std::vector<std::wstring> delimitadores;
	std::vector<std::unique_ptr<Palavra>> palavras;
public:
	Texto(const char*);
	Texto(const std::string &);

	void salvarArquivo(const std::string&) const;

	bool avancarPalavra();
	Palavra getPalavra() const;
	void setPalavra(const Palavra&);
	std::wstring getContexto() const;
};

#endif
