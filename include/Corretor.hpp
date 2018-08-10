/**
 * O arquivo contendo os requisitos da classe
 * Corretor (headers) e a classe em si
 *
 * @file Corretor.hpp
 */
#ifndef CORRETOR
#define CORRETOR

#include <string>
#include <map>

#include "Dicionario.hpp"
#include "Palavra.hpp"
#include "Texto.hpp"

/**
 * A classe Corretor. Realiza a ponte entre a classe
 * Texto e Dicionário através de uma interface comum
 */
class Corretor
{
public:
	/**
	 * Cria um novo corretor com um dicionário no caminho
	 * fornecido e com o texto do caminho fornecido
	 *
	 * @param dicionario O caminho para o arquivo do dicionário
	 * @param texto O caminho para o arquivo de texto
	 * @see Texto
	 * @see Dicionario
	 */
	Corretor(std::string dicionario, std::string texto);

	/**
	 * Avança para a próxima palavra do Texto
	 *
	 * @return `true` se o avanço foi realizado com sucesso
	 * @return `false` se o avanço falhou (fim do arquivo)
	 * @see Texto::avancarPalavra()
	 */
	bool avancarPalavra();

	/**
	 * Checa se a palavra atual existe no dicionário
	 *
	 * @see Dicionario::buscaPalavra(const Palavra& palavra)
	 */
	bool checarPalavra();

	/**
	 * Substitui a palavra atual no texto por outra
	 * @param palavra A palavra que irá substituir a atual
	 * @see Texto::setPalavra(const Palavra& palavra)
	 */
	void setPalavra(const Palavra& palavra);

	/**
	 * Salva a palavra atual no dicionário
	 * @see Texto::getPalavra()
	 * @see Dicionario::inserePalavra(const Palavra& palavra)
	 */
	void salvarPalavra();

	/**
	 * Retorna o contexto da palavra atual
	 *
	 * @see Texto::getContexto()
	 */
	std::wstring getContexto() const;

	/**
	 * Busca o dicionário por palavras semelhantes
	 * (usando a versão lower-case da palavra)
	 *
	 * @return Todas as palavras semelhantes à fornecida
	 * @see Palavra::minuscula()
	 * @see Palavra::semelhante()
	 * @see Dicionario::buscaSemelhantes(const Palavra& palavra)
	 */
	std::vector<Palavra> buscaSemelhantes() const;

	/**
	 * Salva o Texto no caminho fornecido
	 *
	 * @param arquivo O caminho para o arquivo a ser escrito
	 * @see Texto::salvarArquivo(const std::string& arquivo)
	 */
	void salvarTexto(const std::string& arquivo) const;

	/**
	 * Salva o dicionário no arquivo `dic.txt`
	 *
	 * @see Dicionario::salvarArquivo()
	 */
	void salvarDicionario() const;

	/**
	 * Retorna todos os erros encontrados até o momento
	 *
	 * @return Lista(`std::map` indexado por Palavra) de quantidades de erros encontrados por palavra.
	 * @see Corretor::erros
	 */
	std::map<Palavra, int> getErros() const;
private:
	/**
	 * O Dicionário utilizado pelo Corretor.
	 */
	Dicionario dicionario;

	/**
	 * O Texto lido pelo Corretor.
	 */
	Texto texto;

	/**
	 * Lista de quantidades de erros encontrados por palavra.
	 */
	std::map<Palavra, int> erros;
};

#endif
