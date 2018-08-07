#ifndef DICIONARIO
#define DICIONARIO

#include <string>
#include <fstream>
#include <vector>
#include <memory>

#include "Arvore.hpp"
#include "Palavra.hpp"

class Dicionario
{
private:
	Arvore arvore;
	const std::string arquivo;
public:
	Dicionario(const std::string& arquivo);
	void inserePalavra(const Palavra& palavra);
	bool buscaPalavra(const Palavra& palavra) const noexcept;
	std::vector<Palavra> buscaSemelhantes(const Palavra& palavra) const noexcept;
	void salvarArquivo() const;
};

#endif
