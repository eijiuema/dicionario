#ifndef PALAVRA
#define PALAVRA

class Palavra
{
public:
	Palavra(std::string palavra);
	bool semelhante(Palavra);
	~Palavra();
private:
	std::string palavra;
};

bool operator == (Palavra, Palavra);
bool operator < (Palavra, Palavra);
bool operator > (Palavra, Palavra);

#endif