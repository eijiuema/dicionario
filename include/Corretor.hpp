/**
 * @brief O arquivo contendo os requisitos da classe
 * Corretor (headers) e a classe em si
 *
 * @file Corretor.hpp
 */
#ifndef CORRETOR
#define CORRETOR

#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "Dicionario.hpp"
#include "Palavra.hpp"
#include "Texto.hpp"

/**
 * @brief A classe Corretor. Realiza a ponte entre a classe
 * Texto e Dicionário através de uma interface comum
 */
class Corretor
{
public:
	/**
	 * @brief Cria um novo corretor com um dicionário no caminho
	 * fornecido e com o texto do caminho fornecido
	 *
	 * @param dicionario O caminho para o arquivo do dicionário
	 * @param texto O caminho para o arquivo de texto
	 * @callgraph
	 */
	Corretor(std::string dicionario, std::string texto);

	/**
	 * @brief Avança para a próxima palavra do Texto
	 *
	 * @return true O avanço foi realizado com sucesso
	 * @return false O avanço falhou (fim do arquivo)
	 * @see Texto::avancarPalavra()
	 * @callgraph
	 */
	bool avancarPalavra();

	/**
	 * @brief Checa se a palavra atual existe no dicionário
	 *
	 * @return true A palavra existe no dicionário
	 * @return false A palavra não existe no dicionário
	 * @callgraph
	 */
	bool checarPalavra();

	/**
	 * @brief Substitui a palavra atual no texto por outra
	 * @param palavra A palavra que irá substituir a atual
	 * @see Texto::setPalavra(const Palavra&)
	 * @callgraph
	 */
	void setPalavra(const Palavra& palavra);
	void salvarPalavra();
	std::wstring getContexto() const;
	std::vector<Palavra> buscaSemelhantes() const;
	void salvarTexto(const std::string& arquivo) const;
	void salvarDicionario() const;
	std::map<Palavra, int> getErros() const;
private:
	Dicionario dicionario;
	Texto texto;
	std::map<Palavra, int> erros;
};

#endif
