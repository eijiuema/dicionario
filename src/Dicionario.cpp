#include "Dicionario.hpp"

Dicionario::Dicionario(const std::string& arquivo) : arquivo(arquivo)
{
	int lastPos = -1;
	std::wstringstream buffer;
	std::wifstream inputStream(arquivo);
	std::locale loc("");
	inputStream.imbue(loc);

	if(!inputStream)
		throw std::runtime_error("Erro ao abrir o arquivo.");


	while(inputStream.peek() != std::wifstream::traits_type::eof())
	{
		if(lastPos == inputStream.tellg())
		{
			std::cerr << "Stuck on letter '" << (char)inputStream.peek() << "' (offset"
			<< std::hex << inputStream.tellg() << std::dec << ")" << std::endl;
			std::cerr.flush();
			throw std::runtime_error("Stuck on letter.");
		}

		lastPos = inputStream.tellg();

		// Read all leading punctuation and spaces
		while(ispunct((wchar_t) inputStream.peek(), loc) || isspace((char) inputStream.peek(), loc))
			inputStream.get();
		// Then go after the word itself
		while(isalnum((wchar_t) inputStream.peek(), loc) || inputStream.peek() == '-' || inputStream.peek() == '\'')
			buffer << (wchar_t) inputStream.get();

		// // After all of this wcreate a safe pointer and store the buffers' info in it
		if(!buffer.str().empty())
			inserePalavra(Palavra(buffer.str()));

		// // Clear the buffer contents so we don't get trash
		buffer.str(L"");
	}
}

void Dicionario::inserePalavra(const Palavra& palavra)
{
	arvore.insere(palavra.minuscula());
}

bool Dicionario::buscaPalavra(const Palavra& palavra) const noexcept
{
	return arvore.busca(palavra);
}

std::vector<Palavra> Dicionario::buscaSemelhantes(const Palavra& palavra) const noexcept
{
	return arvore.buscaSemelhantes(palavra);
}

void Dicionario::salvarArquivo() const
{
	std::wofstream outputStream(arquivo);

	outputStream.imbue(std::locale(""));

	if(!outputStream)
		throw std::runtime_error("Could not open file.");

	arvore.print(Arvore::print_order::in, outputStream);
}