/**
 * Arquivo contendo requsitos da classe texto (cabeçalhos)
 * e a classe em si
 * @file Texto.hpp
 */

#ifndef TEXTO_H
#define TEXTO_H
#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
#include <vector>
#include <string>
#include <memory>
#include "Palavra.hpp"

/**
 * Gerencia a leitura e escrita de textos
 * no sistema de arquivos e também lê palavras
 * separadas de delimitadores (pontuações, espaços
 * e quebras de linha)
 */
class Texto
{
private:
	/**
	 * O nome do arquivo passado para o construtor
	 */
	std::string nomeArquivo;

	/**
	 * O iterador (posição atual no texto)
	 */
	size_t iterador;

	/**
	 * O vetor de delimitadores lidos pelo construtor.
	 * (sempre terá um delimitador a mais do que o vetor
	 * de palavras)
	 */
	std::vector<std::wstring> delimitadores;

	/**
	 * Um vetor com ponteiros das Palavras lidas pelo
	 * construtor.
	 * (std::unique_ptr<T> garante que memória não irá
	 * vazar e que somente um local terá a posse do
	 * ponteiro)
	 */
	std::vector<std::unique_ptr<Palavra>> palavras;
public:
	/**
	 * Cria um novo objeto da classe Texto com
	 * o conteúdo no arquivo fornecido
	 *
	 * @param fn O caminho para o arquivo
	 * @see Texto::Texto(const std::string& fn)
	 */
	Texto(const char* fn);

	/**
	 * Cria um novo objeto da classe Texto com
	 * o conteúdo no arquivo fornecido.
	 *
	 * @param fn O caminho para o arquivo
	 */
	Texto(const std::string& fn);

	/**
	 * Salva o arquivo no caminho fornecido com
	 * os delimitadores e palavras modificadas
	 *
	 * @param fn O caminho para o arquivo onde o conteúdo
	 * deverá ser escrito
	 */
	void salvarArquivo(const std::string& fn) const;

	/**
	 * Faz o iterador avançar uma posição no texto.
	 *
	 * @return true se avanço foi realizado com sucesso
	 * @return false se não foi possível avançar (fim do texto)
	 */
	bool avancarPalavra();

	/**
	 * Retorna a palavra atual
	 *
	 * @return Palavra A palavra atual
	 * @see Texto::avancarPalavra()
	 * @see Texto::setPalavra()
	 */
	Palavra getPalavra() const;

	/**
	 * Substituir a palavra atual por uma nova
	 *
	 * @param palavra A palavra que deverá substituir a palavra atual
	 * @see Texto::avancarPalavra()
	 * @see Texto::getPalavra()
	 */
	void setPalavra(const Palavra& palavra);

	/**
	 * Retorna o contexto da palavra atual (a palavra atual,
	 * anterior, a posterior juntamente com a pontuação da atual)
	 *
	 * @return std::wstring contendo o contexto da palavra atual
	 */
	std::wstring getContexto() const;
};

#endif
