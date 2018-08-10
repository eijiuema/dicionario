/**
 * Arquivo que contém a classe Palavra e seus requisitos
 *
 * @file Palavra.hpp
 */
#ifndef PALAVRA
#define PALAVRA

#include <algorithm>
#include <iostream>
#include <string>

/**
 * A classe que armazena todas as palavras
 * e funcionalidades relacionadas a elas
 */
class Palavra
{
private:
	/**
	 * A palavra original passada para o construtor
	 */
	std::wstring palavra;
public:
	/**
	 * Cria uma nova palavra
	 *
	 * @param palavra A string contendo a palavra a ser armazenada
	 */
	Palavra(const std::wstring palavra);

	/*
	 * Sem construtor de cópia e sobrecarga do operador de atribuição
	 * já que os padrões gerados pelo compilador são suficientes.
	 */

	/**
	 * Checa se outra palavra é semelhante a esta usando as duas
	 * primeiras letras de ambas.
	 *
	 * @param palavra A palavra com a qual comparar
	 * @return int contendo -1 se esta palavra tiver as duas letras
	 * alfabeticamente antes da palavra fornecida, 0 se forem iguais
	 * e 1 se esta palavra estiver alfabeticamente depois da palavra
	 * fornecida
	 */
	int semelhante(const Palavra& palavra) const;

	/**
	 * Retorna a palavra convertida para *lower-case*
	 *
	 * @return Palavra com seus caractéres convertidos para *lower-case*
	 */
	Palavra minuscula() const;

	/**
	 * Confere se o conteúdo desta palavra é igual ao da palavra fornecida
	 *
	 * @return bool
	 */
	bool operator == (const Palavra& palavra) const;

	/**
	 * Confere se esta palavra estaria antes da palavra fornecida em uma
	 * ordenação alfabética
	 *
	 * @return bool
	 */
	bool operator < (const Palavra& palavra) const;

	/**
	 * Confere se esta palavra estaria após à palavra fornecida em uma ordenação
	 * alfabética
	 *
	 * @return bool
	 */
	bool operator > (const Palavra& palavra) const;

	/**
	 * Retorna a string contendo a palavra armazenada
	 *
	 * @return std::wstring
	 */
	std::wstring getPalavra() const;
};

/**
 * Concatena uma Palavra a uma string
 *
 * @param palavra A palavra no lado esquerdo da operação
 * @param string A string no lado direito da operação
 * @return std::wstring A palavra concatenada com a string
 */
std::wstring operator + (const std::wstring palavra, const Palavra& string);

/**
 * Concatena uma string a uma Palavra
 *
 * @param string A string no lado esquerdo da operação
 * @param palavra A palavra no lado direito da operação
 * @return std::wstring A string concatenada com a palavra
 */
std::wstring operator + (const Palavra& palavra, const std::wstring string);

/**
 * Escreve uma palavra em uma *wide stream*
 *
 * @param outputStream A *stream* na qual escrever
 * @param p A palavra a escrever
 * @return std::wostream& A *stream* na qual a palavra foi escrita
 */
std::wostream &operator << (std::wostream& outputStream, const Palavra& p);

#endif
