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
	int semelhante(const Palavra&) const;
	bool operator == (const Palavra&) const;
	bool operator < (const Palavra&) const;
	bool operator > (const Palavra&) const;
	std::wstring getPalavra() const;
};

std::wstring operator + (const std::wstring, const Palavra&);
std::wstring operator + (const Palavra&, const std::wstring);
std::wostream &operator << (std::wostream&, const Palavra&);

#endif
