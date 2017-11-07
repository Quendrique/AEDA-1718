#include "oferta.h"
#include "fornecedor.h"

#include "empresa.h"
#include <string>
#include <sstream>
#include <fstream>

/*void leofertas(string ficheiro)
{
	vector <Oferta> oferta;
	ifstream fichoferta(ficheiro);
	if (fichoferta.is_open())
	{
		string line;
		while (getline(fichoferta, line))
		{
			stringstream ss;

		}
	}
}*/
void lefornecedores(string ficheiro)
{
	vector <Fornecedor> fornecedor;
	Fornecedor f;
	vector<Oferta> oferta;
	ifstream forne(ficheiro);
	if (forne.is_open())
	{
		string line;
		
		int pos;
		while (getline(forne, line))
		{
			pos = line.find(",", 0);
			f.setNome( line.substr(0, pos));
			

		}
	}
}