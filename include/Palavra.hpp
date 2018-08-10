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
	const std::wstring palavra;
public:
	/**
	 * Cria uma nova palavra
	 *
	 * @param palavra A string contendo a palavra a ser armazenada
	 */
	Palavra(const std::wstring palavra);

	/*
	 * Sem construtor de cópia já que o padrão gerado pelo compilador
	 * é suficiente.
	 */

	/**
	 * Cria e retorna uma
	 *
	 * @param p
	 * @return Palavra
	 */
	Palavra operator=(const Palavra& p);
	int semelhante(const Palavra& palavra) const;
	Palavra minuscula() const;
	bool operator == (const Palavra&) const;
	bool operator < (const Palavra&) const;
	bool operator > (const Palavra&) const;
	std::wstring getPalavra() const;
};

std::wstring operator + (const std::wstring palavra, const Palavra& string);
std::wstring operator + (const Palavra& palavra, const std::wstring string);
std::wostream &operator << (std::wostream& outputStream, const Palavra& p);

#endif
