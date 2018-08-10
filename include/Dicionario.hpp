/**
 * Arquivo contendo o Dicionário e suas dependências
 *
 * @file Dicionario.hpp
 */
#ifndef DICIONARIO
#define DICIONARIO

#include <exception>
#include <fstream>
#include <sstream>
#include <string>
#include <locale>
#include <vector>

#include "Arvore.hpp"
#include "Palavra.hpp"

/**
 * Classe Dicionário. Armazena uma lista de palavras
 * e através de uma Arvore realiza buscas e armazenamento
 * de Palavras
 */
class Dicionario
{
private:
	/**
	 * A Arvore onde as palavras do dicionário estão sendo
	 * armazenadas
	 */
	Arvore arvore;

	/**
	 * O caminho para o arquivo original do dicionário
	 */
	const std::string arquivo;
public:
	/**
	 * Lê o dicionário no caminho fornecido
	 *
	 * Armazena somente palavras descartando toda pontuação,
	 * espaçamento e outros caracteres que não fazem parte
	 * de palavras.
	 *
	 * @param arquivo O caminho para o arquivo a ser interpretado
	 */
	Dicionario(const std::string& arquivo);

	/**
	 * Insere uma palavra no dicionário para as próximas checagens
	 *
	 * @param palavra A palavra a ser inserida no dicionário
	 * @see Arvore::insere(const Palavra&)
	 */
	void inserePalavra(const Palavra& palavra);

	/**
	 * Confere se uma palavra está contida no dicionário
	 *
	 * @param palavra Palavra a ser buscada
	 * @see Arvore::busca(const Palavra&)
	 */
	bool buscaPalavra(const Palavra& palavra) const noexcept;

	/**
	 * Realiza a busca por palavras semelhantes à fornecida
	 *
	 * @param palavra Palavra a ser buscada
	 * @return Um vetor contendo uma cópia de todas as palavras
	 * semelhantes à fornecida
	 * @see Arvore::buscaSemelhantes(const Palavra&)
	 */
	std::vector<Palavra> buscaSemelhantes(const Palavra& palavra) const noexcept;

	/**
	 * @brief Salva o dicionário no seu arquivo original
	 *
	 * Salva os nós da árvore por ordem de nível da árvore
	 * para que não haja necessidade de realizar
	 * rotações no carregamento, garantindo uma inicialização
	 * mais rápida)
	 * @see Arvore::print(print_order, std::wostream&)
	 */
	void salvarArquivo() const;
};

#endif
