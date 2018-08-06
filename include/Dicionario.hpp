#ifndef DICIONARIO
#define DICIONARIO

#include <iostream>
#include <string>
#include <iostream>
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
	bool buscaPalavra(const Palavra& palavra) const noexcept;
	std::vector<Palavra> buscaSemelhantes(const Palavra& palavra) noexcept;
	// ~Dicionario();
};

#endif
