#ifndef CORRETOR
#define CORRETOR

#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "Dicionario.hpp"
#include "Palavra.hpp"
#include "Texto.hpp"

class Corretor
{
public:
	Corretor(std::string dicionario, std::string texto);
	bool avancarPalavra();
	bool checarPalavra();
	void setPalavra(const Palavra&);
	void salvarPalavra();
	std::wstring getContexto() const;
	std::vector<Palavra> buscaSemelhantes() const;
	void salvarTexto(const std::string&) const;
	void salvarDicionario() const;
	std::map<Palavra, int> getErros() const;
private:
	Dicionario dicionario;
	Texto texto;
	std::map<Palavra, int> erros;
};

#endif
