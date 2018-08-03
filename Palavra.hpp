#ifndef PALAVRA
#define PALAVRA
#include <string>
#include <fstream>

class Palavra
{
public:
	Palavra(std::string, std::string);
	bool semelhante(Palavra) const;
	void escreverPalavra(std::ostream &) const;
	std::string getPalavra() const;
	std::string getDelimitadores() const;
	void modificarPalavra(std::string);

	bool operator == (Palavra) const;
	bool operator < (Palavra) const;
	bool operator > (Palavra) const;
private:
	std::string delimitadores;
	std::string palavra;
};

#endif
