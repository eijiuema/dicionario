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
	std::vector<std::wstring> delimitadores;
	std::vector<std::unique_ptr<Palavra>> palavras;
public:
	Texto(const char*);
	Texto(const std::string &);

	void salvarArquivo(std::wostream &) const noexcept;
	void modificarPalavra(const int &, const Palavra &);
	const std::vector<std::unique_ptr<Palavra>>& getPalavras() const noexcept;
};

#endif
