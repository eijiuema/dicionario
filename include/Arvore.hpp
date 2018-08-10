/**
 * O arquivo contendo os requisitos da classe
 * Arvore (headers) e a classe em si
 *
 * @file Arvore.hpp
 */

#ifndef AVL
#define AVL

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include "Palavra.hpp"

/**
 * A classe Arvore. Responsável por armazenar ordenadamente
 * as palavras em uma Árvore AVL.
 */
class Arvore {
public:

	enum class print_order {in, level};

	/**
	 * Cria uma nova árvore vazia (com raíz nula)
	 */
	Arvore();

	/**
	 * Destrói a árvore liberando a memória de todos os seus nós
	 */

	~Arvore();

	/**
	 * Checa se a árvore está vazia
	 *
	 * @return *true* se a árvore estiver vazia
	 * @return *false* se a árvore não estiver vazia
	 */
	bool vazia() const;

	/**
	 * Insere uma palavra na árvore
	 * @param palavra A palavra que será inserida
	 * @see Palavra
	 */
	void insere(const Palavra& palavra);

	/**
	 * Remove uma palavra da árvore
	 * @param palavra A palavra que será removida
	 * @see Palavra
	 */
	void remove(const Palavra& palavra);

	/**
	 * Checa se uma palavra está na árvore
	 *
	 * @param palavra A palavra que será buscada
	 * @return *true* se a palavra estiver na árvore
	 * @return *false* se a palavra não estiver na árvore
	 * @see Palavra
	 */
	bool busca(const Palavra& palavra) const;

	/**
	 * Busca todas as palavras semelhantes a uma palavra
	 *
	 * @param palavra A palavra que será comparada
	 * @return std::vector<Palavra> Palavras semelhantes
	 * @see Palavra
	 * @see Palavra::semelhante()
	 */
	std::vector<Palavra> buscaSemelhantes(const Palavra& palavra) const;

	/**
	 * Imprime as palavras da árvore
	 * @param Arvore::print_order A ordem da impressão
	 * @param stream A *stream* alvo da impressão
	 * @see Arvore::print_order
	 */
	void print(print_order, std::wostream& stream) const;

private:
	/**
	 * A classe No. Responsável por armazenar as palavras
	 * e a estrutura da árvore.
	 */
	class No {
	public:

		/**
		 * Cria um nó com uma palavra
		 * @param palavra Palavra que o nó conterá
		 */
		No(const Palavra& palavra);

		/**
		 * Palavra contida pelo nó
		 */
		Palavra p;

		/**
		 * Ponteiros dos nós filhos esquerdo e direito
		 */
		No *esq, *dir;

		/**
		 * Altura do nó
		 */
		int alt;
	};


	/**
	 * Raíz da árvore
	 */
	No *raiz;

	/**
	 * Insere recursivamente um nó na árvore
	 *
	 * @param no Ponteiro do nó raiz da iteração
	 * @param palavra A palavra a ser inserida
	 * @return Arvore::No* Ponteiro do nó raiz no fim da iteração
	 * @see Arvore::No
	 * @see Palavra
	 */
	No *insereNo(No* no, const Palavra& palavra);

	/**
	 * Busca recursivamente um nó na árvore
	 *
	 * @param no Ponteiro do nó raiz da iteração
	 * @param palavra A palavra a ser buscada
	 * @return Arvore::No* Ponteiro do nó que contém a palavra se a árvore conter a palavra
	 * @return nullptr se a árvore não conter a palavra
	 * @see Arvore::No
	 * @see Palavra
	 */
	No *buscaNo(No* no, const Palavra& palavra) const;

	/**
	 * Busca recursivamente um nó semelhante na árvore e o adiciona
	 * ao vetor semelhantes
	 *
	 * @param no Ponteiro do nó raiz da iteração
	 * @param palavra A palavra a ser comparada
	 * @param palavras Palavras semelhantes
	 * @see Arvore::No
	 * @see Palavra
	 */
	void buscaNoSemelhante(No* no, const Palavra& palavra, std::vector<Palavra>& semelhantes) const;

	/**
	 * Remove recursivamente um nó da árvore
	 *
	 * @param no Ponteiro do nó raiz da iteração
	 * @param palavra A palavra a ser removida
	 * @return Arvore::No* Ponteiro do nó raiz no fim da iteração
	 * @see Arvore::No
	 * @see Palavra
	 */
	No *removeNo(No* no, const Palavra& palavra);

	/**
	 * Busca recursivamente o menor nó da árvore
	 *
	 * @param no Ponteiro do nó raiz da iteração
	 * @return Arvore::No* Ponteiro do menor nó da árvore
	 * @see Arvore::No
	 */
	No *menorNo(No* no) const;

	/**
	 * Calcula recursivamente o fator de balanceamento de um nó
	 *
	 * @param no Ponteiro do nó raiz da iteração
	 * @return int Fator de balanceamento do nó
	 * @see Arvore::No
	 */
	int calcBal(No* no) const;

	/**
	 * Calcula recursivamente a altura de um nó
	 *
	 * @param no Ponteiro do nó raiz da iteração
	 * @return int Altura do nó
	 * @see Arvore::No
	 */
	int altura(No* no) const;

	/**
	 * Rotaciona à esquerda uma árvore
	 *
	 * @param no Ponteiro do nó raiz da árvore
	 * @see Arvore::No
	 */
	No *rotE(No* no);

	/**
	 * Rotaciona à direita uma árvore
	 *
	 * @param no Ponteiro do nó raiz da árvore
	 * @see Arvore::No
	 */
	No *rotD(No* no);

	/**
	 * Imprime recursivamente as palavras dos nós
	 * da árvore num percurso em ordem
	 *
	 * @param no Ponteiro do nó raiz da árvore
	 * @param stream A *stream* alvo da impressão
	 * @see Arvore::No
	 */
	void printInOrderNo(No* no, std::wostream& stream) const;

	/**
	 * Imprime recursivamente as palavras dos nós
	 * da árvore num percurso por nível
	 *
	 * @param no Ponteiro do nó raiz da árvore
	 * @param stream A *stream* alvo da impressão
	 * @see Arvore::No
	 */
	void printLevelOrderNo(No* no, std::wostream& stream) const;
};

#endif
