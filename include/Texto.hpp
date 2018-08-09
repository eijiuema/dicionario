/**
 * @brief Arquivo contendo requsitos da classe texto (cabeçalhos)
 * e a classe em si
 * @file Texto.hpp
 */

#ifndef TEXTO_H
#define TEXTO_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>
#include "Palavra.hpp"

/**
 * @brief Gerencia a leitura e escrita de textos
 * no sistema de arquivos e também lê palavras
 * separadas de delimitadores (pontuações, espaços
 * e quebras de linha)
 */
class Texto
{
private:
	std::string nomeArquivo;
	int iterador = 0;
	std::vector<std::wstring> delimitadores;
	std::vector<std::unique_ptr<Palavra>> palavras;
public:
	/**
	 * @brief Cria um novo objeto da classe Texto com
	 * o conteúdo no arquivo fornecido
	 *
	 * @param fn O caminho para o arquivo
	 */
	Texto(const char* fn);

	/**
	 * @brief Cria um novo objeto da classe Texto com
	 * o conteúdo no arquivo fornecido.
	 *
	 * @param fn O caminho para o arquivo
	 */
	Texto(const std::string& fn);

	/**
	 * @brief Salva o arquivo no caminho fornecido com
	 * os delimitadores e palavras modificadas
	 *
	 * @param fn O caminho para o arquivo onde o conteúdo
	 * deverá ser escrito
	 */
	void salvarArquivo(const std::string& fn) const;

	/**
	 * @brief Faz o iterador avançar uma posição no texto.
	 *
	 * @return true O avanço foi realizado com sucesso
	 * @return false Não foi possível avançar (fim do texto)
	 */
	bool avancarPalavra();

	/**
	 * @brief Retorna a palavra atual
	 *
	 * @return Palavra A palavra atual
	 */
	Palavra getPalavra() const;

	/**
	 * @brief Substituir a palavra atual por uma nova
	 *
	 * @param palavra A palavra que deverá substituir a palavra atual
	 */
	void setPalavra(const Palavra& palavra);

	/**
	 * @brief Retorna o contexto da palavra atual (a palavra atual,
	 * anterior, a posterior juntamente com a pontuação da atual)
	 *
	 * @return std::wstring O contexto da palavra atual
	 */
	std::wstring getContexto() const;
};

#endif
