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
	int semelhante(const Palavra&) const;
	bool operator == (const Palavra&) const;
	bool operator < (const Palavra&) const;
	bool operator > (const Palavra&) const;
	std::string getPalavra() const;
};

std::string operator + (const std::string, const Palavra&);
std::string operator + (const Palavra&, const std::string);
std::ostream &operator << (std::ostream&, const Palavra&);

#endif
