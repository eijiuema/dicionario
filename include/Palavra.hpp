#ifndef PALAVRA
#define PALAVRA

#include <iostream>
#include <string>

class Palavra
{
private:
	const std::wstring palavra;
public:
	Palavra(const std::wstring);
	Palavra(const Palavra&);
	Palavra operator=(const Palavra& p);
	bool semelhante(const Palavra&) const;
	bool operator == (const Palavra&) const;
	bool operator < (const Palavra&) const;
	bool operator > (const Palavra&) const;
	std::wstring getPalavra() const;
};

std::wostream &operator << (std::wostream&, const Palavra&);

#endif
