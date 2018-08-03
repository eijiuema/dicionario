#ifndef PALAVRA
#define PALAVRA

#include <iostream>
#include <string>

class Palavra
{
public:
	Palavra(std::string = "");
	bool semelhante(Palavra);
	std::string palavra;
};

bool operator == (Palavra &, Palavra &);
bool operator < (Palavra &, Palavra &);
bool operator > (Palavra &, Palavra &);
std::ostream &operator << (std::ostream&, const Palavra &);
std::istream &operator >> (std::istream&, Palavra &);

#endif