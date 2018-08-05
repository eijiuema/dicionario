#ifndef PALAVRA
#define PALAVRA

#include <iostream>
#include <string>

class Palavra
{
public:
	Palavra(const std::string);
	Palavra(const Palavra&);
	Palavra operator=(const Palavra& p);
	bool semelhante(const Palavra&) const;
	bool operator == (const Palavra&) const;
	bool operator < (const Palavra&) const;
	bool operator > (const Palavra&) const;
	std::string getPalavra() const;
private:
	const std::string palavra;
};

std::ostream &operator << (std::ostream&, const Palavra&);
std::istream &operator >> (std::istream& is, Palavra &p);

#endif
