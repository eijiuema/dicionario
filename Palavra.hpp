#ifndef PALAVRA
#define PALAVRA

#include <iostream>
#include <string>

class Palavra
{
public:
	Palavra(const std::string);
	bool semelhante(const Palavra&) const;

	bool operator == (const Palavra&) const;
	bool operator < (const Palavra&) const;
	bool operator > (const Palavra&) const;
	std::ostream &operator << (std::ostream&, const Palavra&) const;
	std::istream &operator >> (std::istream& is, Palavra &p);
private:
	const std::string palavra;
};

#endif
