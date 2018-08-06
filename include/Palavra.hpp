#ifndef PALAVRA
#define PALAVRA

#include <iostream>
#include <string>

class Palavra
{
private:
	const std::string palavra;
public:
	Palavra(const std::string);
	Palavra(const Palavra&);
	Palavra operator=(const Palavra& p);
	bool semelhante(const Palavra&) const;
	bool operator == (const Palavra&) const;
	bool operator < (const Palavra&) const;
	bool operator > (const Palavra&) const;
	std::string getPalavra() const;
};

std::ostream &operator << (std::ostream& os, const Palavra& p)

#endif
